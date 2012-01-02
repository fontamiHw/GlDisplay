/*
 * Arrows.cpp
 *
 *  Created on: Dec 31, 2011
 *      Author: mfontane
 */

#include "Arrows.h"

Arrows::Arrows( unsigned int _x,  unsigned int _y, unsigned int delta) {
    xL= _x;
    y=_y;
    deltaX = delta;
    xDir = xL + delta/2 +arrowLeft[0]/2;
    xR =  xL+arrowLeft[0]+deltaX;
}

Arrows::~Arrows() {
}


void Arrows::arrowLeftOn(boolean on){
    if (on) {
        GLCD.DrawBitmap(arrowLeft, xL, y, BLACK);
    } else {
        GLCD.FillRect(xL, y, arrowLeft[0], arrowLeft[1], WHITE);
    }
}

void Arrows::arrowRigthOn(boolean on) {
    if (on) {
        GLCD.DrawBitmap(arrowRigth, xR, y, BLACK);
    } else {
        GLCD.FillRect(xR, y, arrowRigth[0], arrowRigth[1], WHITE);
    }
}

void Arrows::arrowForwardOn(boolean on) {
    if (on) {
        GLCD.DrawBitmap(arrowUp, xDir, y, BLACK);
    } else {
        GLCD.FillRect(xDir, y, arrowUp[0], arrowUp[1], WHITE);
    }
}

void Arrows::arrowBackwardOn(boolean on) {
    if (on) {
        GLCD.DrawBitmap(arrowDown, xDir, y, BLACK);
    } else {
        GLCD.FillRect(xDir, y, arrowDown[0], arrowDown[1], WHITE);
    }
}

