/*
 * Dashboard.h
 *
 *  Created on: Jan 1, 2012
 *      Author: mfontane
 */

#ifndef DASHBOARD_H_
#define DASHBOARD_H_

#include <glcd.h>    // Graphics LCD library

#include "Arrows.h"
#include "dial/speedMeter/SpeedMeter.h"
#include "dial/speedMeter/clock/Clock.h"

class Dashboard {
private:
    Dashboard():arrows(Arrows(5, GLCD.CenterY+10,(2)-(2*arrowLeft[0]))){} // NEVER USE THIS

    ;
    Arrows arrows;
    SpeedMeter speedMeter;
    Clock clock;
    unsigned int actualSpeed;
    boolean forward;
    byte radius;
    int changeDir;

public:
    Dashboard(byte _radius);
    virtual ~Dashboard();
    void init();
    void update();
    void arrowLeftOn(boolean on);
    void arrowRigthOn(boolean on);
    void increaseSpeed();
    void reduceSpeed();
    void setSpeed(int speed, boolean _direction);
};

#endif /* DASHBOARD_H_ */
