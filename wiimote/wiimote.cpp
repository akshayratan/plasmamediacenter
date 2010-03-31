/*
 * Copyright 2010 Sebastian Kügler <sebas@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) version 3, or any
 * later version accepted by the membership of KDE e.V. (or its
 * successor approved by the membership of KDE e.V.), which shall
 * act as a proxy defined in Section 6 of version 3 of the license.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 */

// Qt
#include <QTime>
#include <QTimer>

// KDE
#include <KDebug>

#include "wiimote.h"

//cwiid_mesg_callback_t print_callback;

Wiimote* myWiimote = 0;

Wiimote::Wiimote( QObject* parent )
    : QThread(parent),
    m_wiimote(0),
    m_ledState(0),
    m_state(0)
{
    // Be the global object used to pass on events
    // from the static callback function
    myWiimote = this;
}

Wiimote::~Wiimote()
{
    disconnectWiimote();
    delete m_state;
    kDebug() << "gone";
}

WiimoteState* Wiimote::state()
{
    return m_state;
}

void Wiimote::cwiidCallback(cwiid_wiimote_t *wiimote, int mesg_count,
                    union cwiid_mesg mesg[], struct timespec *timestamp)
{
    if (myWiimote) {
        myWiimote->wiimoteEvent(wiimote, mesg_count, mesg, timestamp);
    }
}

void Wiimote::wiimoteEvent(cwiid_wiimote_t *wiimote, int mesg_count,
                    union cwiid_mesg mesg[], struct timespec *timestamp)
{
    Q_UNUSED( timestamp );
    int i;
    for (i=0; i < mesg_count; i++) {
        switch (mesg[i].type) {
        case CWIID_MESG_BTN:
            updateButtons(mesg[i].btn_mesg.buttons);
            break;
        case CWIID_MESG_ACC:
            updateAccelerometers(mesg[i].acc_mesg);
            break;
        case CWIID_MESG_STATUS:
            printf("Status Report: battery=%d extension=",
                   mesg[i].status_mesg.battery);
            switch (mesg[i].status_mesg.ext_type) {
            case CWIID_EXT_NONE:
                printf("none");
                break;
            case CWIID_EXT_NUNCHUK:
                printf("Nunchuk");
                break;
            case CWIID_EXT_CLASSIC:
                printf("Classic Controller");
                break;
            default:
                printf("Unknown Extension");
                break;
            }
            printf("\n");
            break;
        case CWIID_MESG_IR:
            updateInfrared(mesg[i].ir_mesg);
            break;
        case CWIID_MESG_ERROR:
            if (cwiid_close(wiimote)) {
                fprintf(stderr, "Error on wiimote disconnect\n");
                exit(-1);
            }
            //exit(0);
            break;
        default:
            printf("Unknown Report");
            break;
        }
    }

    updateStatus();
}

void Wiimote::updateAccelerometers(struct cwiid_acc_mesg acc)
{

    bool changed = false;
    int x, y, z;

    x = acc.acc[CWIID_X];
    y = acc.acc[CWIID_Y];
    z = acc.acc[CWIID_Z];

    if (x != m_state->accelX) {
        m_state->accelX = x;
        emit accelerometerXChanged(x);
        changed = true;
    }

    if (y != m_state->accelY) {
        m_state->accelY = y;
        emit accelerometerYChanged(y);
        changed = true;
    }

    if (z != m_state->accelZ) {
        m_state->accelZ = z;
        emit accelerometerZChanged(z);
        changed = true;
    }

    if (changed) {
        emit accelerometerChanged(x, y, z);
    }
}

void Wiimote::updateInfrared(struct cwiid_ir_mesg ir_mesg)
{
    //bool changed = false;
    int oldcount = m_state->infrared.count();
    m_state->infrared.clear();
    for (int i = 0; i < CWIID_IR_SRC_COUNT; i++) {
        if (ir_mesg.src[i].valid) {
            //changed = true;
            int x = ir_mesg.src[i].pos[CWIID_X];
            int y = ir_mesg.src[i].pos[CWIID_Y];
            m_state->infrared << QPoint(x, y);
        }
    }
    if (m_state->infrared.count()) {
        emit infraredChanged();
    } else {
        if (oldcount) { // Also update if sources have vanished
            emit infraredChanged();
        }
    }
}

void Wiimote::updateButtons(uint16_t buttons)
{
    /* Button flags
    #define CWIID_BTN_2     0x0001
    #define CWIID_BTN_1     0x0002
    #define CWIID_BTN_B     0x0004
    #define CWIID_BTN_A     0x0008
    #define CWIID_BTN_MINUS 0x0010
    #define CWIID_BTN_HOME  0x0080
    #define CWIID_BTN_LEFT  0x0100
    #define CWIID_BTN_RIGHT 0x0200
    #define CWIID_BTN_DOWN  0x0400
    #define CWIID_BTN_UP    0x0800
    #define CWIID_BTN_PLUS  0x1000
    */

    // Up Button
    if ((buttons & CWIID_BTN_UP) != m_state->buttonUpPressed) {
        m_state->buttonUpPressed = buttons & CWIID_BTN_UP;
        emit buttonUp(m_state->buttonUpPressed);
    }

    // Down Button
    if ((buttons & CWIID_BTN_DOWN) != m_state->buttonDownPressed) {
        m_state->buttonDownPressed = buttons & CWIID_BTN_DOWN;
        emit buttonDown(m_state->buttonDownPressed);
    }

    // Left Button
    if ((buttons & CWIID_BTN_LEFT) != m_state->buttonLeftPressed) {
        m_state->buttonLeftPressed = buttons & CWIID_BTN_LEFT;
        emit buttonLeft(m_state->buttonLeftPressed);
    }

    // Right Button
    if ((buttons & CWIID_BTN_RIGHT) != m_state->buttonRightPressed) {
        m_state->buttonRightPressed = buttons & CWIID_BTN_RIGHT;
        emit buttonRight(m_state->buttonRightPressed);
    }

    // A Button
    if ((buttons & CWIID_BTN_A) != m_state->buttonAPressed) {
        m_state->buttonAPressed = buttons & CWIID_BTN_A;
        emit buttonA(m_state->buttonAPressed);

        // We're using this button for debugging:
        if (m_state->buttonAPressed) {
            cwiid_get_state(m_wiimote, &m_wiimoteState);
            dumpState(&m_wiimoteState);
        }
    }

    // B Button
    if ((buttons & CWIID_BTN_B) != m_state->buttonBPressed) {
        m_state->buttonBPressed = buttons & CWIID_BTN_B;
        emit buttonB(m_state->buttonBPressed);
    }

    // Minus Button
    if ((buttons & CWIID_BTN_MINUS) != m_state->buttonMinusPressed) {
        m_state->buttonMinusPressed = buttons & CWIID_BTN_MINUS;
        emit buttonMinus(m_state->buttonMinusPressed);
    }

    // Home Button
    if ((buttons & CWIID_BTN_HOME) != m_state->buttonHomePressed) {
        m_state->buttonHomePressed = buttons & CWIID_BTN_HOME;
        emit buttonHome(m_state->buttonHomePressed);
    }

    // Plus Button
    if ((buttons & CWIID_BTN_PLUS) != m_state->buttonPlusPressed) {
        m_state->buttonPlusPressed = buttons & CWIID_BTN_PLUS;
        emit buttonPlus(m_state->buttonPlusPressed);
    }

    // 1 Button
    if ((buttons & CWIID_BTN_1) != m_state->buttonOnePressed) {
        m_state->buttonOnePressed = buttons & CWIID_BTN_1;
        emit buttonOne(m_state->buttonOnePressed);
    }

    // 2 Button
    if ((buttons & CWIID_BTN_2) != m_state->buttonTwoPressed) {
        m_state->buttonTwoPressed = buttons & CWIID_BTN_2;
        emit buttonTwo(m_state->buttonTwoPressed);
    }
}

void Wiimote::run()
{
    m_state = new WiimoteState;
    m_state->connected = false;
    m_state->battery = 0;
    connectWiimote();
}

bool Wiimote::connectWiimote()
{
    /* Get device info */
    int bdinfo_count = 0;
    char ba_str[18];
    struct cwiid_bdinfo *bdinfo;
    int i;
    uint8_t flags = 0;

    if ((bdinfo_count = cwiid_get_bdinfo_array(-1, 2, -1, &bdinfo, flags)) == -1) {
        kDebug() << "nothing found :(";
        return -1;
    }

    /* Print info */
    for (i=0; i < bdinfo_count; i++) {
        ba2str(&bdinfo[i].bdaddr, ba_str);
        //printf("%s 0x%.2X%.2X%.2X %s\n", ba_str, bdinfo[i].btclass[2],
        //           bdinfo[i].btclass[1], bdinfo[i].btclass[0], bdinfo[i].name);
        m_state->deviceClass = QString(bdinfo[i].btclass[0]);
        m_state->deviceName = QString(bdinfo[i].name);
        emit statusChanged(QString("%1 %2 found. \nPress 1+2 on your wiimote.").arg(m_state->deviceClass, m_state->deviceName));
        kDebug() << "Found Wimote:" << m_state->deviceClass << m_state->deviceName;
        m_state->btAddress = QString(ba_str);
    }

    str2ba(m_state->btAddress.toLatin1(), &m_bdaddr);

    while (!(m_state->connected)) {
        // Connect to the wiimote
        printf("Put your wiimote in discoverable mode now (press 1+2)...\n");
        if (!(m_wiimote = cwiid_open(&m_bdaddr, 0))) {
            fprintf(stderr, "Unable to connect to wiimote\n");
            emit statusChanged("Unable to connect to wiimote\n");
            //return false;
        } else {
            m_state->connected = true;
        }
    }
    kDebug() << "Connected!";
    emit connected();
    emit statusChanged(QString("Connected to Wiimote: %1 %2").arg(m_state->deviceName, m_state->deviceClass));
    if (cwiid_set_mesg_callback(m_wiimote, cwiidCallback)) {
        kDebug() << "Unable to set message callback";
        emit statusChanged("Unable to set message callback");
    }

    unsigned char rpt_mode = 0;

    // Enable the following events from the wiimote
    rpt_mode = rpt_mode | CWIID_RPT_ACC;
    rpt_mode = rpt_mode | CWIID_RPT_BTN;
    //rpt_mode = rpt_mode | CWIID_RPT_EXT;
    rpt_mode = rpt_mode | CWIID_RPT_IR; // Enable when adding support for the IR sensor
    //rpt_mode = rpt_mode | CWIID_RPT_STATUS;

    if (cwiid_set_rpt_mode(m_wiimote, rpt_mode)) {
        kDebug() << "Error setting report mode";
    }

    if (cwiid_enable(m_wiimote, CWIID_FLAG_MESG_IFC)) {
        kDebug() << "Error enabling messages";
    }

    return true;
}

void Wiimote::disconnectWiimote()
{
    if (m_wiimote) {
        cwiid_close(m_wiimote);
    }
    m_wiimote = 0;
    m_state->connected = false;
    emit statusChanged("Wiimote disconnected");
    emit disconnected();
}

void Wiimote::updateStatus()
{
    //int t = QTime::currentTime().msec();
    //kDebug() << "...update...";
    if (m_wiimote && cwiid_get_state(m_wiimote, &m_wiimoteState)) {
        emit statusChanged("Error getting state :(");
        kDebug() << "Error getting state";
        return;
    }
    //kDebug() << dumpState(&m_wiimoteState);
    updateBattery(&m_wiimoteState);
    m_ledState = m_wiimoteState.led;
    //int t2 = QTime::currentTime().msec();
    //kDebug() << "time:" << t2 - t;
}

void Wiimote::updateBattery(struct cwiid_state *state)
{
    int b = (int)(100.0 * state->battery / CWIID_BATTERY_MAX);
    //kDebug() << "Battery:" << b;
    if (b != m_state->battery) {
        m_state->battery = b;
        emit batteryChanged(b);
    }
}

QString Wiimote::dumpState(struct cwiid_state *state)
{
    QString output;
    int i;
    int valid_source = 0;

    output.append("Report Mode:");
    if (state->rpt_mode & CWIID_RPT_STATUS) output.append(" STATUS");
    if (state->rpt_mode & CWIID_RPT_BTN) output.append(" BTN");
    if (state->rpt_mode & CWIID_RPT_ACC) output.append(" ACC");
    if (state->rpt_mode & CWIID_RPT_IR) output.append(" IR");
    if (state->rpt_mode & CWIID_RPT_NUNCHUK) output.append(" NUNCHUK");
    if (state->rpt_mode & CWIID_RPT_CLASSIC) output.append(" CLASSIC");
    output.append("\n");

    output.append("Active LEDs:");
    if (state->led & CWIID_LED1_ON) output.append(" 1");
    if (state->led & CWIID_LED2_ON) output.append(" 2");
    if (state->led & CWIID_LED3_ON) output.append(" 3");
    if (state->led & CWIID_LED4_ON) output.append(" 4");
    output.append("\n");


    output.append(QString("\nRumble: %1").arg(state->rumble ? "On" : "Off"));

    output.append(QString("\nBattery: %1%%").arg(
           (int)(100.0 * state->battery / CWIID_BATTERY_MAX)));

    //output.append(QString("\nButtons: %1").arg( state->buttons));

    //output.append(QString("\nAccelerometers: x=%1 y=%2 z=%3\n").arg(state->acc[CWIID_X], state->acc[CWIID_Y],
    //       state->acc[CWIID_Z]));
    output.append("\nIR: ");
    kDebug() << "- - - - - - - - - - IR:";
    for (i = 0; i < CWIID_IR_SRC_COUNT; i++) {
        if (state->ir_src[i].valid) {
            valid_source = 1;
            //output.append(QString("(%1,%2) ").arg(state->ir_src[i].pos[CWIID_X],
            //                   state->ir_src[i].pos[CWIID_Y]));
            kDebug() << state->ir_src[i].pos[CWIID_X] << state->ir_src[i].pos[CWIID_Y];
        }
    }

    if (!valid_source) {
        output.append("No IR sources found");
    }
    output.append("\n");

    switch (state->ext_type) {
    case CWIID_EXT_NONE:
        output.append("No extension\n");
        break;
    case CWIID_EXT_UNKNOWN:
        output.append("\nUnknown extension attached\n");
        break;
    case CWIID_EXT_NUNCHUK:
    case CWIID_EXT_CLASSIC:
        break;
    }
    //emit statusChanged(output);
    //kDebug() << output;
    return output;
}

bool Wiimote::ledOne()
{
    return m_state->ledOne;
}

bool Wiimote::ledTwo()
{
    return m_state->ledOne;
}

void Wiimote::setLeds()
{
    if (m_wiimote) {
        int n = cwiid_set_led(m_wiimote, m_ledState);
        kDebug() << n << m_ledState;
    }
}

void Wiimote::rumble(bool on)
{
    if (m_wiimote) {
        if (cwiid_set_rumble(m_wiimote, on)) {
            kDebug() << "Error setting rumble";
        }
    }
}

void Wiimote::ledOneOn()
{
    m_ledState = m_ledState | CWIID_LED1_ON;
    setLeds();
}

void Wiimote::ledOneOff()
{
    m_ledState = m_ledState & ~CWIID_LED1_ON;
    setLeds();
}

void Wiimote::ledTwoOn()
{
    m_ledState = m_ledState | CWIID_LED2_ON;
    setLeds();
}

void Wiimote::ledTwoOff()
{
    m_ledState = m_ledState & ~CWIID_LED2_ON;
    setLeds();
}

void Wiimote::ledThreeOn()
{
    m_ledState = m_ledState | CWIID_LED3_ON;
    setLeds();
}

void Wiimote::ledThreeOff()
{
    m_ledState = m_ledState & ~CWIID_LED3_ON;
    setLeds();
}

void Wiimote::ledFourOn()
{
    m_ledState = m_ledState | CWIID_LED4_ON;
    setLeds();
}

void Wiimote::ledFourOff()
{
    m_ledState = m_ledState & ~CWIID_LED4_ON;
    setLeds();
}

#include "wiimote.moc"