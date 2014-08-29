#include "Moon.h"
#include <math.h>


void DrawCircle(double r,double cx,double cy)
{
    double const PI = 3.14159;
    double w = 600.0, h = 400.0;
    glBegin(GL_POLYGON);
        glColor4f( 255/255.0 , 250/255.0, 218/255.0, 0.6);
        glVertex3f(cx,cy,0.0);

        for(double t = 0; t<PI*2;t+=0.2)
        {
            glColor4f( 255/255.0 , 250/255.0, 218/255.0, 0.1);
            glVertex3f(cx+r/w*cos(t),cy+r/h*sin(t),0.0);
        }
        glVertex3f(cx+r/w*cos(0.0),cy+r/h*sin(0.0),0.0);
    glEnd();
}


void Moon::drawMoon(double &xPos, double &yPos, double &radius) {
    glPushMatrix();
        DrawCircle(radius, xPos, yPos);
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