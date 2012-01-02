/*
 * Clock.h
 *
 *  Created on: Dec 31, 2011
 *      Author: mfontane
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "../SpeedMeter.h"

class Clock : private SpeedMeter {

private :

    byte l_hour        ; /* length of hour hand                           */
    byte l_second      ; /* length of second hand                         */

    /* Previous positions of hour and minute hands */
    byte PX_Hour   ; /* previous x-coordinate of hour hand   */
    byte PY_Hour   ; /* previous y-coordinate of hour hand   */
    byte PX_Minute ; /* previous x-coordinate of minute hand */
    byte PY_Minute ; /* previous y-coordinate of minute hand */
    byte PX_Second ; /* previous x-coordinate of second hand */
    byte PY_Second ; /* previous y-coordinate of second hand */

    byte Hours; /* current hours                    */
    byte Minutes; /* current minutes                  */
    byte Seconds; /* current seconds                  */

    byte DigRow; /* row position of digital clock    */
    byte DigColumn; /* column position of digital clock */
    byte Offset; /* time offset from system clock    */

    byte DateRow; /* row position of date string      */
    byte DateColumn; /* column position of date string   */

    void SegBox(byte FaceAngle);


public:
    Clock();
    virtual ~Clock();
    void DisplayTime( byte hours, byte minutes, byte seconds = -1 ); // draw hands in the position for the given hours and minutes
    void drawFace();
    void init(byte x, byte y, byte r);
};

#endif /* CLOCK_H_ */
