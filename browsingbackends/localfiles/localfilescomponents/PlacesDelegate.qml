/***************************************************************************
 *   Copyright 2012 Sinny Kumari <ksinny@gmail.com>                        *
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
import org.kde.plasma.components 0.1 as PlasmaComponents
import org.kde.qtextracomponents 0.1 as QtExtraComponents

Rectangle {
    color: "black"
    opacity: 0.8
    border.color: "white"
    Row {
        anchors { fill: parent; margins: 5 }
        spacing: 10
        QtExtraComponents.QIconItem {
            id: delegateItemIcon
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height; width: height
            icon: decoration
        }

        PlasmaComponents.Label {
            anchors.verticalCenter: parent.verticalCenter
            text: display
            font.pointSize: 14
            color: "white"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                backend.browseToPlace(index)
            }
        }
    }
}