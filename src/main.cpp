/*
 * clockFace.pde
 *
 * analog clock using the GLCD library
 *
 * uses pushbuttons to set the time
 * defualt connections are pins 2 and 3
 * connect one side of a button to a pin, the other side to ground
 * one button advances time forward, the other moves it back
 *
 */
#include <glcd.h>    // Graphics LCD library

#include "dashBoard/Dashboard.h"
//#include "dashBoard/dial/speedMeter/clock/Clock.h"
//#include "dashBoard/Arrows.h"

#define PULL_UP  HIGH

const int  btnForward = 2;  // buttons to set clock hands
const int  btnBack = 3;


Dashboard dashboard = Dashboard(GLCD.CenterY-4);
//SpeedMeter speedMeter = SpeedMeter();  // this creates an instance of the analog clock display.
//Clock clock = Clock();  // this creates an instance of the analog clock display.
//Arrows arrows = Arrows(5, GLCD.CenterY+10,(radius*2)-(2*arrowLeft[0]));
unsigned int actualSpeed;

void checkSetButton(int button, int direction)
{
    const int stepSecs[] = {1,30,300};  // values used to accelerate movement when button held down
    int stepIndex = 0; // the index to determine accelartion value
    int step = 0; // counts steps between each index increment

    if(digitalRead(button)== LOW)
    {
        delay(50);  // debounce time
        unsigned long startTime = millis() + 1000;
        while(digitalRead(button)== LOW)
        {
            if(millis() - startTime > 100){
                startTime = millis();
//                adjustTime(stepSecs[stepIndex] * direction);
//#ifdef DISPLAY_HEIGHT < 64
//                // small clocks scribble over numbers so redraw face
//                clock.drawFace();
//#endif
//                clock.DisplayTime(hour(), minute(), second() ); // update analog clock
                if( ++step > 30){
                    step=0;
                    if(stepIndex < 2){
                        stepIndex++;
                    }
                }
            }
//            if (direction == 1)
                dashboard.arrowLeftOn(true);
//            else
                dashboard.arrowRigthOn(true);
        }
        actualSpeed += direction;
//        if (direction == 1)
        dashboard.arrowLeftOn(false);
//        else
        dashboard.arrowRigthOn(false);
    }
}

void setup(){
    digitalWrite(btnForward, PULL_UP);
    digitalWrite(btnBack, PULL_UP);
//    GLCD.Init(); // start the GLCD code
//    GLCD.SelectFont(System5x7);
//    setTime(4, 37, 0, 2, 1, 10); // set time to 4:37 am Jan 2 2010
//    speedMeter.init(radius+4, GLCD.CenterY+4, radius);  // draw the clock face
//    clock.init(3*radius+12, GLCD.CenterY, radius);  // draw the clock face
//    actualSpeed=0;
//    arrows.arrowLeftOn(false);
//    arrows.arrowRigthOn(false);
    dashboard.init();
}

void  loop(){
    unsigned long  prevtime;
//    prevtime = now();
//    while( prevtime == now() )
//    {
        // check if set buttons pressed while waiting for second to rollover
        checkSetButton(btnForward, 1);
        checkSetButton(btnBack, -1);
//    }

   dashboard.update();
}

int main(void) {

    /* Must call init for arduino to work properly */
    init();
    setup();

    for (;;) {
        loop();
    } // end for
} // end main
