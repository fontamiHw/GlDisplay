/*
 * Dial.h
 *
 *  Created on: Dec 31, 2011
 *      Author: mfontane
 */

#ifndef DIAL_H_
#define DIAL_H_


#include <WProgram.h>

#include <glcd.h>  // this dial uses the Graphics LCD library for display
class Dial
{
private:
    /* Sizes and positions of clock */
    byte x_centre; /* x-coordinate of clock centre                  */
    byte y_centre; /* y-coordinate of clock centre                  */
    byte radius; /* radius of clock face                          */
    byte radius_aspect; /* radius of clock face adjuted for aspect ratio */
    void init(byte x, byte y, byte r); // x & y are the coordinates of the center of the dial, r is the radius of the dial face


protected:
    void CalcHands(byte angle, byte radius, byte *x, byte *y);
    void Box(byte x, byte y, boolean big=true);


public:
    // Public Methods
    Dial();
    void InitFullDial(byte x, byte y, byte r); //  x & y are the coordinates of the center of the clock, r is the radius of the clock face    void DrawFace();
    void InitHalfDial(byte x, byte y, byte r); //  x & y are the coordinates of the center of the clock, r is the radius of the clock face    void DrawFace();
    inline byte getCentre_x() const{return x_centre;};
    inline byte getCentre_y() const{return y_centre;};
    byte getRadius() const;
    byte getRadiusAspect() const;
    inline void setCentre_x(byte centre){x_centre = centre;};
    inline void setCentre_y(byte centre){y_centre = centre;};
    void setRadius(byte radius);
    void setRadiusAspect(byte radiusAspect);
    virtual void drawFace(){};
};


#endif /* DIAL_H_ */
