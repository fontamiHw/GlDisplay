/*
 * Dashboard.cpp
 *
 *  Created on: Jan 1, 2012
 *      Author: mfontane
 */
#include <Time.h>
#include "fonts/SystemFont5x7.h"

#include "Dashboard.h"

Dashboard::Dashboard(byte _radius):
changeDir(false),
radius(_radius),
arrows(Arrows(5, GLCD.CenterY+10,(radius*2)-(2*arrowLeft[0]))){
    speedMeter = SpeedMeter();
    clock = Clock();
}

void Dashboard::init() {
    GLCD.Init(); // start the GLCD code
    GLCD.SelectFont(System5x7);
    setTime(12, 00, 0, 2, 1, 12); // set time to 4:37 am Jan 2 2010
    speedMeter.init(radius+4, GLCD.CenterY+4, radius);  // draw the speed face
    clock.init(3*radius+12, GLCD.CenterY, radius);  // draw the clock face
    actualSpeed=0;
    arrows.arrowLeftOn(false);
    arrows.arrowRigthOn(false);
}

void Dashboard::update() {
    speedMeter.speed(actualSpeed);
    if (changeDir) {
        if (forward)
            arrows.arrowForwardOn(true);
        else
            arrows.arrowBackwardOn(true);
    }
    clock.DisplayTime(hour(), minute(), second() ); // update analog clock
}


void Dashboard::arrowLeftOn(boolean on){
    arrows.arrowLeftOn(on);
}
void Dashboard::arrowRigthOn(boolean on){
    arrows.arrowRigthOn(on);
}

Dashboard::~Dashboard() {
}

void Dashboard::increaseSpeed() {
    actualSpeed++;
}

void Dashboard::reduceSpeed(){
    actualSpeed--;
}

void Dashboard::setSpeed(int speed, boolean _direction) {
    actualSpeed = speed*3;
    if (forward!=_direction){
        changeDir = true;
        forward = _direction;
    } else {
        changeDir = false;
    }
}

