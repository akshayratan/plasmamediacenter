/***************************************************************************
 *   Copyright 2009 by Alessandro Diaferia <alediaferia@gmail.com>         *
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
#include "youtubeprovider.h"

#include "youtubeinterface.h"

YouTubeProvider::YouTubeProvider(QObject *parent, const QVariantList &args) : VideoProvider(parent, args),
m_interface(new YouTubeInterface(this))
{
    setServiceId("youtube");
    connect(m_interface, SIGNAL(result(QString,QList<VideoPackage>)), this, SIGNAL(searchResult(QString,QList<VideoPackage>)));
}

YouTubeProvider::~YouTubeProvider()
{}

void YouTubeProvider::query(const QString &searchTerm, const QVariantList &args)
{
    Q_UNUSED(args);
    m_interface->query(searchTerm);
}

VIDEOPROVIDER_EXPORT(YouTubeProvider)