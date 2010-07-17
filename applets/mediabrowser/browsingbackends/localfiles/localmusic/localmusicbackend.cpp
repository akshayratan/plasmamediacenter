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
#include "localmusicbackend.h"

#include <mediabrowserlibs/mediabrowser_export.h>
#include <mediacenter/mediacenterstate.h>
#include <Nepomuk/Query/ResourceTypeTerm>
#include "nfo.h"

MEDIABROWSER_BACKEND_EXPORT(LocalMusicBackend)

LocalMusicBackend::LocalMusicBackend(QObject *parent, const QVariantList &args) :
LocalFilesAbstractBackend("LocalMusic", parent, args)
{

    m_acceptedMimePrefix = "audio/";
    m_term = Nepomuk::Query::ResourceTypeTerm(Vocabulary::NFO::Audio());
    setRequiredMode(MediaCenter::MusicMode);
}

LocalMusicBackend::~LocalMusicBackend()
{}
