#include <math.h>
#include <iostream>
#include "Moon.h"


using namespace std;


void DrawCircle(double r,double cx,double cy, double alpha)
{
    double const PI = 3.14159;
    double w = 600.0, h = 400.0;
    glBegin(GL_POLYGON);
        glColor4f( 255/255.0 , 242/255.0, 151/255.0, alpha);
        glVertex3f(cx,cy,0.0);
        for(double t = 0; t<PI*2;t+=0.2)
        {   
            glColor4f( 255/255.0 , 242/255.0, 151/255.0, alpha);
            glVertex3f(cx+r/w*cos(t),cy+r/h*sin(t),0.0);
        }
        glVertex3f(cx+r/w*cos(0.0),cy+r/h*sin(0.0),0.0);
    glEnd();
}

inline int in(int x, int min, int max) {
    if(x > min && x < max) {
        return true;
    }
    return false;
}


void Moon::drawMoon(double &xPos, double &yPos, double &radius) {
	glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        int count = 0;
        for(double i=10.0; i >= 6.0; i = i - 0.1) {
            count ++;
            if(in(count, 30, 40)) {
                DrawCircle(radius * (i / 10.0), xPos, yPos, 0.25);
            } else if(in(count, 20, 30)) {
                DrawCircle(radius * (i / 10.0), xPos, yPos, 0.2);
            } else if(in(count, 10, 20)) {
                DrawCircle(radius * (i / 10.0), xPos, yPos, 0.15);
            } else if(in(count, 0, 10)) {
                DrawCircle(radius * (i / 10.0), xPos, yPos, 0.1);
            }
        }
        DrawCircle(radius * 0.6, xPos, yPos, 0.6);
    glPopMatrix();

    // Animate 
    xPos += 0.0001;
    radius += 0.005;
    if(xPos > 1.4) {
        xPos = -1.4;
        radius = 100.0;
    }

      yPos = -0.22 * xPos * xPos + 1.2 * xPos;
}