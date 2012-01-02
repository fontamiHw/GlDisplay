/*
 * SpeedMeter.cpp
 *
 *  Created on: Dec 31, 2011
 *      Author: mfontane
 */

#include "SpeedMeter.h"

SpeedMeter::SpeedMeter() {
}

SpeedMeter::~SpeedMeter() {
}

void SpeedMeter::init(byte x, byte y, byte r) {
    l_tick = (r*3) / 3 ;
    InitHalfDial(x, y, r);
}

void SpeedMeter::drawFace() {
    byte hr, x, y ;
    for( hr = 45; hr <= 60; hr += 2 ) {
        //        if ( !( hr % 15 ) )
        //        this->SegBox( hr ) ; /* draw quarter hour shapes */
        //                else{
        this->CalcHands( hr, getRadius(), &x, &y ) ;
        this->Box( x, y, false ) ;
        //        }
    }

    for( hr = 0; hr <= 15; hr += 2 ) {
        //        if ( !( hr % 15 ) )
        //        this->SegBox( hr ) ; /* draw quarter hour shapes */
        //                else{
        this->CalcHands( hr, getRadius(), &x, &y ) ;
        this->Box( x, y, false ) ;
        //        }
    }
}

void SpeedMeter::speed(byte newSpeed) {
    /* erase previous hands */
    unsigned int xCentre;
    unsigned int yCentre;


    xCentre = getCentre_x();
    yCentre = getCentre_y();
    byte x;
    byte y;
        CalcHands( actualSpeed, l_tick, &x, &y ) ;
        GLCD.DrawLine( xCentre, yCentre, x, y, WHITE ) ;

    if (newSpeed > 15)
        newSpeed -= 15;
    else
        newSpeed += 45;
    actualSpeed = newSpeed;
    CalcHands( actualSpeed, l_tick, &x, &y ) ;
    GLCD.DrawLine( xCentre, yCentre, x, y, BLACK ) ;

    InitHalfDial(xCentre, yCentre, getRadius());
}

