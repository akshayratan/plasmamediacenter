/***************************************************************************
 *   Copyright 2010 by Christophe Olinger <olingerc@binarylooks.com>       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include "homestate.h"

#include <mediacenter/browser.h>
#include <mediacenter/playbackcontrol.h>
#include <mediacenter/playlist.h>
#include <mediacenter/player.h>
#include <mediacenter/infodisplay.h>
#include <mediacenter/medialayout.h>
#include <mediacenter/private/sharedlayoutcomponentsmanager.h>

#include <KApplication>


using namespace MediaCenter;

HomeState::HomeState (QState *parent)
    : MediaCenterState(parent),
    m_quit(new Plasma::IconWidget())
{}

HomeState::~HomeState()
{
}

void HomeState::onExit(QEvent* event)
{
    Q_UNUSED(event);

    SharedLayoutComponentsManager::self()->barAutohideControlWidget()->setVisible(true);
    SharedLayoutComponentsManager::self()->homeWidget()->setVisible(true);

    m_layout->setInfoDisplayOnly(false);
}

void HomeState::onEntry(QEvent* event)
{
    Q_UNUSED(event);

    emit state(MediaCenter::HomeMode);

    showBackgroundStates();

    SharedLayoutComponentsManager::self()->barAutohideControlWidget()->setVisible(false);
    SharedLayoutComponentsManager::self()->homeWidget()->setVisible(false);
}

QList<QGraphicsWidget*> HomeState::subComponents() const
{
    QList<QGraphicsWidget*> list;

    m_quit->setIcon("system-shutdown");
    list << m_quit;
    m_infoDisplay->addToLayout(m_quit, MediaCenter::RightZone);

    return list;
}

void HomeState::configure()
{
    m_browser->showStartupState();

    m_browser->setVisible(true);
    m_player->setVisible(false);
    m_playlist->setVisible(false);
    m_control->setVisible(false);
    if (SharedLayoutComponentsManager::self()->isBackgroundMusicMode() ||
        SharedLayoutComponentsManager::self()->isBackgroundVideoMode() ||
        SharedLayoutComponentsManager::self()->isBackgroundPictureMode()) {
        m_control->setVisible(true);
    }

    m_browser->clearViewModes();
    m_browser->setShowingBrowsingWidgets(false);

    m_layout->setPlaylistVisible(false);
    m_layout->setInfoDisplayOnly(true);
}

void HomeState::initConnections()
{
    connect (m_quit, SIGNAL(clicked()), kapp, SLOT(quit()));
}