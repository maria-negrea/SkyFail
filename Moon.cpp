#include <math.h>
#include <iostream>
#include "Moon.h"


using namespace std;

/*!
* Draws one circle with radius *r*, center point having coordinates *cx*, *cy*
* and the alpha for points

* The circle is drawn using a number of polygons, all having one points in the center (cx, cy)

* @param[in] r Double -- Radius
* @param[in] cx Double -- OX coordinate for center point
* @param[in] cy Double -- OY coordinate for center point
* @param[in] alfa Double -- The alpha parameter (transparency)
*/
void Moon::DrawCircle(double r,double cx,double cy, double alpha)
{
    double const PI = 3.14159;
    double w = 600.0, h = 400.0;
    glBegin(GL_POLYGON);
        glColor4f( 241/255.0 , 215/255.0, 166/255.0, alpha);
        glVertex3f(cx,cy,0.0);
        for(double t = 0; t<PI*2;t+=0.2)
        {   
            glColor4f(252/255.0 , 244/255.0, 226/255.0, alpha);
            glVertex3f(cx+r/w*cos(t),cy+r/h*sin(t),0.0);
        }
        glVertex3f(cx+r/w*cos(0.0),cy+r/h*sin(0.0),0.0);
    glEnd();
}

/*!
* Helper function, determines if *x* is in the interval determined by *min* and *max*
*/
inline int in(int x, int min, int max) 
{
    if(x > min && x < max) 
	{
        return true;
    }
    return false;
}

/*!
* Draws the moon using circles with the same center but different transparency parameters and radius

* @param[in] xPos Double -- OX parameter for center
* @param[in] yPos Double -- OY parameter for center
* @param[in] radius Double -- Radius
*/
void Moon::drawMoon(double &xPos, double &yPos, double &radius) 
{
	glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        int count = 0;
        for(double i=10.0; i >= 6.0; i = i - 0.1) 
		{
            count ++;
            if(in(count, 30, 40)) 
			{
                DrawCircle(radius * (i / 10.0), xPos, yPos, 0.25);
            } else if(in(count, 20, 30)) 
			{
                DrawCircle(radius * (i / 10.0), xPos, yPos, 0.2);
            } else if(in(count, 10, 20)) 
			{
                DrawCircle(radius * (i / 10.0), xPos, yPos, 0.15);
            } else if(in(count, 0, 10)) 
			{
                DrawCircle(radius * (i / 10.0), xPos, yPos, 0.1);
            }
        }
        Moon::DrawCircle(radius * 0.6, xPos, yPos, 0.0);
    glPopMatrix();

    // Animate 
    xPos += 0.001;
    radius += 0.005;
    if(xPos > 1.4) 
	{
        xPos = -1.4;
        radius = 100.0;
    }

    yPos = -0.22 * xPos * xPos + 1.2 * xPos;
    // glFlush();
}