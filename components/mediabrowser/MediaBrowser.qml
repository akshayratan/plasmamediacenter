/*
 *   Copyright 2011 Sinny Kumari <ksinny@gmail.com>
 *   Copyright 2010 Lukas Appelhans <l.appelhans@gmx.de>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

import QtQuick 1.1
import org.kde.plasma.components 0.1 as PlasmaComponents
import org.kde.plasma.mediacentercomponents 0.1 as MediaCenterComponents

FocusScope {
    id: mediaBrowser
    property QtObject currentBrowsingBackend

    signal playRequested(int index, string url, string currentMediaType)

    Item {
        id: mediaBrowserViewItem
        property QtObject mediaBrowserGridView

        anchors.fill: parent
    }

    Component {
        id: mediaBrowserViewComponent
        GridView {
            anchors { fill: parent; topMargin: 10; bottomMargin: 10 + searchMedia.height }
            clip: true
            cellWidth: width / 5
            cellHeight: cellWidth
            preferredHighlightBegin: parent.width*0.1
            preferredHighlightEnd: parent.width*0.9
            highlightRangeMode: GridView.ApplyRange
            delegate: MediaItemDelegate {
                backend: currentBrowsingBackend
                onPlayRequested: mediaBrowser.playRequested(index, url, currentMediaType)
            }
            flow: GridView.TopToBottom
            model: mediaBrowser.currentBrowsingBackendModel
        }
    }

    onCurrentBrowsingBackendChanged: {
        currentBrowsingBackend.init();

        var object;
        if (currentBrowsingBackend.mediaBrowserOverride()) {
            var qmlSource = currentBrowsingBackend.mediaBrowserOverride();
            object = Qt.createQmlObject(qmlSource, mediaBrowserViewItem);
            mediaBrowserViewItem.mediaBrowserGridView = object;
            object.backend = (function() { return currentBrowsingBackend; });
        } else {
            object = mediaBrowserViewComponent.createObject(mediaBrowserViewItem);
        }
        mediaBrowserViewItem.mediaBrowserGridView = object;
        object.focus = true

        if (currentBrowsingBackend.supportsSearch()) {
            searchMedia.visible = true
        } else {
            searchMedia.visible = false
        }
    }

    function destroyGridView()
    {
        mediaBrowserViewItem.mediaBrowserGridView.destroy()
    }
    function loadModel()
    {
        //JS snippet to do mediaBrowserGridView.model: currentBrowsingBackend.backendModel
        mediaBrowserViewItem.mediaBrowserGridView.model = (function() { return currentBrowsingBackend.backendModel; });
    }

     PlasmaComponents.TextField {
         id: searchMedia
         width: parent.width
         height: 30
         clearButtonShown: true
 
         anchors {
             left: parent.left
             bottom: parent.bottom
             right: parent.right
             margins: 10
         }
 
         placeholderText: "Search..."
         onTextChanged: currentBrowsingBackend.search(text);
     }
}
