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

Item {
    id: rootItem
    property alias model: imageList.model
    property alias currentIndex: imageList.currentIndex
    signal imageClicked(string url)

    PlasmaComponents.ToolButton {
        id: button1
        height: parent.height; width: height
        anchors { left: parent.left; top: parent.top; bottom: parent.bottom }
        iconSource: "go-previous"
        onClicked: {
            var i = imageList.currentIndex
            if (i>0) imageList.currentIndex = i - 1
        }
    }

    PlasmaComponents.ToolButton {
        id: slideshow
        anchors.left: button1.right
        height: parent.height
        checkable: true
        width: height
        iconSource: checkable ? "media-playback-start" : "media-playback-pause"
        flat: true
        onClicked: checkable = !checkable
        Timer {
            id: slideshowTimer
            interval: 4000; running: !slideshow.checkable ; repeat: true
            onTriggered: {
                var i = imageList.currentIndex;
                if (i<imageList.count-1) { imageList.currentIndex = i + 1; emitClicked() }
            }
        }
    }

    ListView {
        id: imageList
        anchors { left: slideshow.right; right: button2.left; top: parent.top; bottom: parent.bottom }

        orientation: ListView.Horizontal
        spacing: 2
        preferredHighlightBegin: parent.width*0.4
        preferredHighlightEnd: parent.width*0.6
        highlightRangeMode: GridView.ApplyRange
        delegate: PictureStripDelegate {
            height: 64
            width: isExpandable ? 0 : height
            onImageClicked: rootItem.imageClicked(url)
        }
        focus: true
    }

    PlasmaComponents.ToolButton {
        id: button2
        height: parent.height; width: height
        anchors { right: parent.right; top: parent.top; bottom: parent.bottom }
        iconSource: "go-next"
        onClicked: {
            var i = imageList.currentIndex
            if (i<imageList.count-1) imageList.currentIndex = i + 1
        }
    }
}