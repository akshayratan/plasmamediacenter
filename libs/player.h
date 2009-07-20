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
#ifndef PLAYER_H
#define PLAYER_H

#include "mediacenter_export.h"

#include <Plasma/Applet>

#include <mediacenter.h>

namespace Phonon {
    class MediaObject;
}

namespace MediaCenter {

/**
 * @typedef Media defines a QPair of MediaCenter::MediaType and QString.
 * The first argument is the type of the media while the second is a QString
 * defining the media. It might be both an udi string pointing to the device
 * hosting the media or the path to a media file.
 */
typedef QPair<MediaCenter::MediaType, QString> Media;

/**
 * @class Player player.h
 * @brief Is the main class for handling the reproduction of all MediaTypes.
 *
 * This class is the main class that should be reimplemented when writing
 * a mediaplayer applet for the MediaCenter. Every supported MediaCenter::MediaType
 * has to be handled by this class.
 */

class MEDIACENTER_EXPORT Player : public Plasma::Applet
{
    Q_OBJECT
public:
    Player(QObject *parent, const QVariantList &args);
    virtual ~Player();

    /**
     * You must reimplement this method in order to return the
     * correct Phonon::MediaObject used to reproduce audio/video
     * content passed to the applet by the MediaContainment that will
     * host it.
     *
     * @note: Note that due to some Phonon limitations you will always
     * have to notify when the current reproduced media type changes to
     * one Phonon does not support, for example a picture (MediaCenter::Picture).
     * The notification should be done via currentTypeChanged(MediaCenter::MediaType) signal.
     */
    virtual Phonon::MediaObject *mediaObject() = 0;

    /**
     * Reimplement this function in order to return the current
     * path to the current reproducing media. If the current media
     * is a MediaCenter::Dvd/MediaCenter::Vcd/MediaCenter::Cd just return
     * the device name containing the media. Use Solid in order to retrieve it.
     */
    virtual QString currentMedia();

    /**
     * This method is used to set the slideshow interval when
     * showing queues of pictures.
     */
    virtual void setSlideshowInterval(qint64 time);

//    /**
//     * You must reimplement this function in order to
//     * provide a list of supported mime types the player can
//     * enqueue and play.
//     *
//     * @return: mime types in the form of: "image/jpeg, video/mpeg..."
//     * @note: wildcards "*" are not supported.
//     */
//    virtual QStringList mimeTypes() = 0;

signals:
    /**
     * Take care of emitting this signal whenever the reproduced
     * MediaType changes.
     *
     * @note: Note that the MediaContainment will use this signal
     * to inform every applet that the current MediaType has changed and
     * will completely ignore the currentSourceChanged() from the Phonon::MediaObject
     * returned by mediaObject().
     */
    void currentTypeChanged(MediaCenter::MediaType newType);

    /**
     * This signal should be emitted whenever the user
     * directly tries to reproduce media via the player.
     * This could happen for example when the user drops media files
     * on the player instead of the playlist.
     *
     * @param medias: the list of media received by the user.
     */
    void mediaReceived(const QList<Media> &medias);

public slots:
    /**
     * You must reimplement this method in order to set the proper volume.
     */
    virtual void setVolume(qreal volume) = 0;

    virtual void skipForward() = 0;
    virtual void skipBackward() = 0;

    virtual void stop() = 0;
    virtual void playPause() = 0;

    /**
     * You must reimplement this method in order to let the user
     * seek the media. This method should do anything if the
     * current media is a picture.
     */
    virtual void seek(int time) = 0;

        /**
     * Reimplement this method in order to store and properly set the queue
     * for reproduction.
     *
     * @note: The default implementation does nothing.
     */
    virtual void setQueue(const QList<Media> &sources);

    /**
     * Reimplement this method to let the host containment update the queue as needed.
     *
     * @note: The default implementation does nothing.
     */
    virtual void enqueue(const QList<Media> &sources);

    /**
     * This slot is called when one or more media are going to be
     * enqueued at a specified index.
     */
    virtual void enqueue(int index, const QList<Media> &sources);
};
}

#endif // PLAYER_H