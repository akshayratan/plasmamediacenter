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
#ifndef PICTUREVIEWER_H
#define PICTUREVIEWER_H

#include <QGraphicsWidget>

class PictureViewer : public QGraphicsWidget
{
    Q_OBJECT
public:
    PictureViewer(QGraphicsItem *parent = 0);
    ~PictureViewer();

    void loadPicture(const QString &path);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int showTime();

public Q_SLOTS:
    void setShowTime(int time);

Q_SIGNALS:
    void showFinished();

private:
    QImage *m_picture;
    int m_showTime;
    QTimer *m_timer;
};

#endif // PICTUREVIEWER_H