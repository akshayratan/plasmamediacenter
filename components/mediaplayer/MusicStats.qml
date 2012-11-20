/***************************************************************************
 *   Copyright 2012 Shantanu Tushar <shantanu@kde.org>                     *
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

import QtQuick 1.1
import org.kde.qtextracomponents 0.1 as QtExtraComponents

Row {
    property variant metaData

    Item {
        id: musicStatsLeftPane
        height: parent.height; width: parent.width*0.4
        QtExtraComponents.QIconItem {
            icon: metaData ? "media-optical-audio" : ""
            anchors { fill: parent; margins: 10 }
        }
    }
    Item {
        id: musicStatsRightPane
        height: parent.height; width: parent.width*0.6

        Column {
            anchors.centerIn: parent
            width: 0.9*parent.width; height: 0.7*parent.height
            StatsLabel { text: metaData.title ? metaData.title : "" }
            StatsLabel { text: metaData.albumArtist ? metaData.albumArtist : "" }
            StatsLabel { text: metaData.albumTitle ? metaData.albumTitle : "" }
            StatsLabel { text: metaData.genre ? metaData.genre : "" }
            StatsLabel { text: metaData.year ? metaData.year : "" }
        }
    }
}