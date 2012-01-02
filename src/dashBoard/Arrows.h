/*
 * Arrows.h
 *
 *  Created on: Dec 31, 2011
 *      Author: mfontane
 */

#ifndef ARROWS_H_
#define ARROWS_H_


#include <WProgram.h>
#include <inttypes.h>
#include <avr/pgmspace.h>

#include <glcd.h>  // this dial uses the Graphics LCD library for display

static uint8_t arrowLeft[] PROGMEM = {
        10, // width
        8, // height

        0x08, 0x1C, 0x3E, 0x7F, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, };

static uint8_t arrowRigth[] PROGMEM = {
        10, // width
        8, // height

        0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x7F, 0x3E, 0x1C, 0x08};

static uint8_t arrowUp[] PROGMEM = {
        8, // width
        8, // height

        0, 0x08, 0x0C, 0xFE, 0xFF, 0xFE, 0x0C, 0x08};

static uint8_t arrowDown[] PROGMEM = {
        8, // width
        8, // height

        0, 0x10, 0x30, 0x7F, 0xFF, 0x7F, 0x30, 0x10};

class Arrows {
private:
    Arrows(){};
    unsigned int xL;
    unsigned int xR;
    unsigned int y;
    unsigned int deltaX;
    unsigned int xDir;

public:
    Arrows( unsigned int _x,  unsigned int _y, unsigned int delta);
    virtual ~Arrows();
    void arrowLeftOn(boolean on);
    void arrowRigthOn(boolean on);
    void arrowForwardOn(boolean on);
    void arrowBackwardOn(boolean on);
};

#endif /* ARROWS_H_ */
