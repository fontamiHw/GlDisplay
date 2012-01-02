/*
 * Dial.cpp
 *
 *  Created on: Dec 31, 2011
 *      Author: mfontane
 */

#include "Dial.h"

#include <glcd.h>  // this clock uses the Graphics LCD library for display

/* Look-up sine table for integer math */
byte byteSine[16] = {0,  27,  54,  79, 104, 128, 150, 171, 190, 201, 221, 233, 243, 250, 254, 255} ;

Dial:: Dial( )
{
}

void Dial::InitFullDial(byte x, byte y, byte r)
{
    GLCD.DrawCircle(x,y, r + 3,BLACK); // draw the surrounding circle
    this->init(x, y, r);
}

void Dial::InitHalfDial(byte x, byte y, byte r)
{
    GLCD.DrawHalfCircle(x,y, r + 3,BLACK); // draw the surrounding circle
    this->init(x, y, r);
}

void Dial::init (byte x, byte y, byte r) {
    /* calculate sizes and position of clock */
    x_centre = x ;
    y_centre = y ;
    radius = r ;
    this->drawFace() ; /* draw the face dial   */
}


void Dial::CalcHands( byte angle, byte radius, byte *x, byte *y )
/* angle is location of hand on dial (0-60)          */
/* radius is length of hand                           */
/* *x   return x-coordinate of hand on dial face */
/* *y   return y-coordinate of hand on dial face */
{
    short quadrant, x_flip, y_flip ;

    /* calculate which quadrant the hand lies in */
    quadrant = angle/15 ;


    /* setup for reflection or rotation */
    switch ( quadrant ) {
    case 0 : x_flip = 1 ; y_flip = -1 ; break ;
    case 1 : angle = abs(angle-30) ; x_flip = y_flip = 1 ; break ;
    case 2 : angle = angle-30 ; x_flip = -1 ; y_flip = 1 ; break ;
    case 3 : angle = abs(angle-60) ; x_flip = y_flip = -1 ; break ;
    default:  x_flip = y_flip =1; // this should not happen
    }

    *x = x_centre ;
    *y = y_centre ;
    *x += ( x_flip*(( byteSine[angle]*radius ) >> 8 )) ;
    *y += ( y_flip*(( byteSine[15-angle]*radius ) >> 8 )) ;
}



byte Dial::getRadius() const
{
    return radius;
}

byte Dial::getRadiusAspect() const
{
    return radius_aspect;
}


void Dial::setRadius(byte radius)
{
    this->radius = radius;
}

void Dial::setRadiusAspect(byte radiusAspect)
{
    radius_aspect = radiusAspect;
}


void Dial::Box( byte x, byte y, boolean  big  )
/* draw a 3 x 3 pixel box centered at x,y */
{
    byte color = BLACK;
    if (big) {
        GLCD.DrawLine( x-1, y-1, x+1, y-1,color ) ;
        GLCD.DrawLine( x-1, y,   x+1, y, color ) ;
        GLCD.DrawLine( x-1, y+1, x+1, y+1,color ) ;
    } else {
        GLCD.DrawLine( x-1, y-1, x, y-1,color ) ;
        GLCD.DrawLine( x-1, y,   x, y, color ) ;
    }
}
