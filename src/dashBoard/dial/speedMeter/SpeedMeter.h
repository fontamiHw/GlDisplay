/*
 * SpeedMeter.h
 *
 *  Created on: Dec 31, 2011
 *      Author: mfontane
 */

#ifndef SPEEDMETER_H_
#define SPEEDMETER_H_

#include "../Dial.h"

class SpeedMeter: protected Dial {

private:
    byte actualSpeed;

protected:
    byte l_tick      ; /* length of arrow hand  */


public:
    SpeedMeter();
    virtual ~SpeedMeter();
    void drawFace();
    void init(byte x, byte y, byte r);
    void speed(byte newSpeed);
};

#endif /* SPEEDMETER_H_ */
