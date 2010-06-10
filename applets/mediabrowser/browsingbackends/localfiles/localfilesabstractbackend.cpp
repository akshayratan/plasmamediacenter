/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include "localfilesabstractbackend.h"

#include <KFilePlacesModel>
#include <KFileDialog>
#include <KDirLister>
#include <KDirModel>
#include <KLineEdit>
#include <KConfigDialog>

#include <QDir>

#include <Nepomuk/ResourceManager>
#include <Nepomuk/Variant>
#include <Nepomuk/Query/ResourceTypeTerm>
#include <Nepomuk/Query/QueryServiceClient>
#include <Nepomuk/Query/FileQuery>

#include "nfo.h"
#include "nie.h"


LocalFilesAbstractBackend::LocalFilesAbstractBackend(const QString& name, QObject* parent, const QVariantList& args) :
AbstractBrowsingBackend(parent, args),
m_acceptedMimePrefix(QString()),
m_backendName(name),
m_model(0),
m_fromPlaces(false),
m_folderNavigation(false),
m_useNepomuk(false)
{
    Nepomuk::ResourceManager::instance()->init();
    setHasConfigurationInterface(true);
}

LocalFilesAbstractBackend::~LocalFilesAbstractBackend()
{

}

QAbstractItemModel* LocalFilesAbstractBackend::model()
{
    if (!m_model) {
        m_model = new KDirModel(this);
        initModel();
    }

    return m_model;
}

void LocalFilesAbstractBackend::setBackendName(const QString& name)
{
    m_backendName = name;
}

QString LocalFilesAbstractBackend::backendName() const
{
    return m_backendName;
}

void LocalFilesAbstractBackend::createConfigurationInterface(KConfigDialog* parent)
{
    QWidget *localConfig = new QWidget(parent);
    ui.setupUi(localConfig);

    parent->addPage(localConfig, i18n("Local Browsing"), "folder-development");

    KFilePlacesModel *model = new KFilePlacesModel(parent);
    ui.placesCombo->setModel(model);

    if (m_fromPlaces) {
        ui.showPlace->setChecked(true);
        ui.placesCombo->setCurrentIndex(model->closestItem(m_localUrl).row());
    } else {
        ui.showCustomFolder->setChecked(true);
        ui.urlRequester->lineEdit()->setText(m_localUrl.url());
    }

    ui.folderNavigationCheckBox->setChecked(m_folderNavigation);
    ui.urlRequester->setMode(KFile::Directory);

    connect (parent, SIGNAL(accepted()), this, SLOT(configAccepted()));
    connect(ui.nepomukBox, SIGNAL(toggled(bool)), ui.tab2, SLOT(setDisabled(bool)));
    connect(ui.addFoldersButton, SIGNAL(clicked()), this, SLOT(getWatchedDirsList()));
    connect(ui.removeFoldersButton, SIGNAL(clicked()), this, SLOT(removeItem()));

    ui.addFoldersButton->setIcon(KIcon("list-add"));
    ui.removeFoldersButton->setIcon(KIcon("list-remove"));

    ui.nepomukBox->setChecked(m_useNepomuk);

    foreach(const QString &folder, m_watchedDirs) {
        ui.watchedFoldersList->addItem(folder);
    }
}

void LocalFilesAbstractBackend::init()
{
    KConfigGroup cf = config();

    m_localUrl = KUrl(cf.readEntry(m_backendName + "Url", QDir::homePath()));
    m_fromPlaces = cf.readEntry(m_backendName + "FromPlaces", true);
    m_folderNavigation = cf.readEntry(m_backendName + "FolderNavigation", true);
    m_useNepomuk = cf.readEntry(m_backendName + "Nepomuk", true);
    m_watchedDirs = cf.readEntry(m_backendName + "WatchedFolders", QStringList());
}

void LocalFilesAbstractBackend::getWatchedDirsList()
{
    KUrl url = KFileDialog::getExistingDirectoryUrl();
    for (int i = 0; i < ui.watchedFoldersList->count(); i++) {
        if (ui.watchedFoldersList->item(i)->text() == url.prettyUrl()) {
            return;
        }
    }
    ui.watchedFoldersList->addItem(url.prettyUrl());
}

void LocalFilesAbstractBackend::removeItem()
{
    qDeleteAll(ui.watchedFoldersList->selectedItems());
}

void LocalFilesAbstractBackend::configAccepted()
{
    KConfigGroup cf = config();

    bool useNepomuk = ui.nepomukBox->isChecked();

    if (useNepomuk) {
        QStringList watchedDirs;
        for (int i = 0; i < ui.watchedFoldersList->count(); i++) {
            watchedDirs << ui.watchedFoldersList->item(i)->text();
        }
        m_watchedDirs = watchedDirs;

        cf.writeEntry("WatchedFolders", m_watchedDirs);
    } else {
        m_fromPlaces = ui.showPlace->isChecked();
        m_localUrl = m_fromPlaces ? ui.placesCombo->model()->index(ui.placesCombo->currentIndex(), 0).data(KFilePlacesModel::UrlRole).value<QUrl>()
                                    : ui.urlRequester->url();
        qobject_cast<KDirLister*>(m_model->dirLister())->openUrl(m_localUrl);

        cf.writeEntry("LocalPicturesUrl", m_localUrl);
        cf.writeEntry("PicturesFromPlaces", m_fromPlaces);

        bool folderNavigation = ui.folderNavigationCheckBox->isChecked();
        if (m_folderNavigation != folderNavigation) {
            m_folderNavigation = folderNavigation;
            cf.writeEntry("PicturesFolderNavigation", m_folderNavigation);
            setFolderNavigation();
        }
    }

    if (useNepomuk != m_useNepomuk) {
        m_useNepomuk = useNepomuk;
        cf.writeEntry("Nepomuk", m_useNepomuk);
    }
    cf.sync();
    initModel();
}

void LocalFilesAbstractBackend::initModel()
{
    if (m_useNepomuk) {
        m_model->dirLister()->setMimeFilter(QStringList());

        Nepomuk::Query::FileQuery query;
        query.setTerm(Nepomuk::Query::ResourceTypeTerm(Vocabulary::NFO::Image()));
        foreach (const QString &folder, m_watchedDirs) {
            query.addIncludeFolder(folder);
        }

        m_model->dirLister()->stop();
        m_model->dirLister()->openUrl(query.toSearchUrl());
    } else {
        KMimeType::List mimeList = KMimeType::allMimeTypes();

        foreach (KMimeType::Ptr mime, mimeList) {
            if (mime->name().startsWith(m_acceptedMimePrefix)) {
                m_mimeTypes << mime->name();
            }
        }
        setFolderNavigation();
        m_model->dirLister()->openUrl(m_localUrl);
    }
}

void LocalFilesAbstractBackend::setFolderNavigation()
{
    if (m_folderNavigation) {
        if (!m_mimeTypes.contains("inode/directory")) {
            m_mimeTypes << "inode/directory";
        }
    } else {
        if (m_mimeTypes.contains("inode/directory")) {
            m_mimeTypes.removeAll("inode/directory");
        }
    }
    KDirLister *lister = qobject_cast<KDirLister*>(m_model->dirLister());
    if (lister) {
        lister->setMimeFilter(m_mimeTypes);
    }
}