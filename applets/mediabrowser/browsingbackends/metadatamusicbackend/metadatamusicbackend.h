/***************************************************************************
 *   Copyright 2009 by Alessandro Diaferia <alediaferia@gmail.com>         *
 *   Copyright 2011 Sinny Kumari <ksinny@gmail.com>
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

#ifndef METADATAMUSICBACKEND_H
#define METADATAMUSICBACKEND_H

#include <libs/mediacenter/abstractbrowsingbackend.h>

class MetadataMusicBackend : public MediaCenter::AbstractBrowsingBackend
{
    Q_OBJECT
public:
    MetadataMusicBackend (QObject* parent, const QVariantList& args);
    virtual ~MetadataMusicBackend();

    virtual void init();
    virtual bool goOneLevelUp();
};

#endif // METADATAMUSICBACKEND_H