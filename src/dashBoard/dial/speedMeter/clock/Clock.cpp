/*
 * Clock.cpp
 *
 *  Created on: Dec 31, 2011
 *      Author: mfontane
 */

#include "Clock.h"

Clock::Clock() {
    // TODO Auto-generated constructor stub

}

Clock::~Clock() {
    // TODO Auto-generated destructor stub
}

void Clock::init(byte x, byte y, byte r)
{
    /* calculate sizes and position of clock */
    Dial::InitFullDial(x,y,r);
    l_hour =  r / 2 ; // hour hand is half radius
    l_tick = (r*3) / 4 ;  // minute hand is 3/4 radius
    l_second  = l_tick + 1;  // second hand is 2 pixels larger than minute


    /* Initialise previous positions of hour and minute hand */
    PX_Hour = PX_Minute = PX_Second = getCentre_x() ;
    PY_Hour = PY_Minute = PY_Second = getCentre_y() ;
}

void Clock::DisplayTime( byte hours, byte minutes, byte seconds )
/* draw the hands at the specified positions */
{
    byte angle ;

    if( hours == 0 )
        hours = 12 ;

    unsigned int xCentre;
    unsigned int yCentre;

    xCentre = getCentre_x();
    yCentre = getCentre_y();

    /* erase previous hands */
    GLCD.DrawLine( xCentre, yCentre, PX_Hour, PY_Hour, WHITE ) ;
    GLCD.DrawLine( xCentre, yCentre, PX_Minute, PY_Minute, WHITE ) ;
    // GLCD.SetDot(PX_Second, PY_Second, WHITE);
    GLCD.DrawCircle(PX_Second, PY_Second,1, WHITE);

    /* calculate new position of minute hand and draw it */
    angle = minutes ;
    CalcHands( angle, l_tick, &PX_Minute, &PY_Minute ) ;
    GLCD.DrawLine( xCentre, yCentre, PX_Minute, PY_Minute, BLACK ) ;

    /* calculate new position of hour hand and draw it */
    angle = ( ( 5*hours ) + ( minutes/12 ) ) % 60 ;
    this->CalcHands( angle, l_hour, &PX_Hour, &PY_Hour ) ;
    GLCD.DrawLine( xCentre, yCentre, PX_Hour, PY_Hour, BLACK ) ;

    /* calculate new position of second hand and draw if requested */
    if( seconds != -1)
    {
        this->CalcHands( seconds, l_second, &PX_Second, &PY_Second ) ;
        //GLCD.SetDot( PX_Second, PY_Second, BLACK ) ;
        GLCD.DrawCircle(PX_Second, PY_Second,1, BLACK);
    }

    /* re-draw clock centre */
    Box( xCentre, yCentre ) ;
}

void Clock::SegBox( byte FaceAngle )
/* draw quarter hour dial markers */
/* FaceAngle is position of marker around face (0-55) */
{
    byte quadrant;
    byte hour;
    unsigned int xCentre;
    unsigned int yCentre;

    xCentre = getCentre_x();
    yCentre = getCentre_y();
    unsigned int rad;
    rad = getRadius();
    /* find the nearest quadrant to the marker position */
    quadrant = ( ( FaceAngle + 7 ) / 15 ) ;
    hour =  FaceAngle == 0 ? 12 : FaceAngle  / 5;

    switch( quadrant ) {
    case 0 :
    case 4 :  // 12 oclock
        GLCD.GotoXY(xCentre-6,  yCentre - rad -1 );
        break;
    case 1 : // 3 oclock
        GLCD.GotoXY(xCentre + rad - 3,  yCentre -3 );
        break;
    case 2 : // 6 oclock
        GLCD.GotoXY(xCentre-2,  yCentre + rad -5);
        break;
    case 3 : // 9 oclock
        GLCD.GotoXY(xCentre- rad ,  yCentre -3 );
        break;
    }
    GLCD.PrintNumber(hour);
}
void Clock::drawFace() {
    byte hr, x, y ;

    Box( getCentre_x(), getCentre_y() ) ; // draw center box


    /* draw hour marks or numerals around the clock face */
    for( hr = 0; hr < 60; hr += 5 ) {
        if ( !( hr % 15 ) )
            this->SegBox( hr ) ; /* draw quarter hour shapes */
        else{
            this->CalcHands( hr, getRadius(), &x, &y ) ;
            this->Box( x, y ) ;
        }
    }
}
