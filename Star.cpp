#include<math.h>
#include "Star.h"
#include "Moon.h"

Star::Star()
{
	outerRadius=0.03;
	innerRadius=0.01;
}

float Star:: getOuterRadius()
{
	return this->outerRadius;
}

float Star:: getInnerRadius()
{
	return this->innerRadius;
}

/*!
* Draws one star (takes color as parameter - r [red], g [green], b [blue])
* Star is created by drawing 10 triangles. The star will have an innerRadius
* and outerRadius which belong to the Star class
*/
void Star::draw(int r, int g, int b, double alfa)
{
	
	const float PI = 3.1415926535897932384626433832795;
	const float STP = 1.0;
	
	glBegin(GL_TRIANGLE_FAN);
		
		glColor4f( r/255.0, g/255.0, b/255.0, alfa*10);
		glVertex3f(center.x, center.y, 0.0);
		
		for (int iVertIndex = 0; iVertIndex < 10; ++iVertIndex) 
		{
			float fAngleStart	= PI/2.0 + (iVertIndex*2.0*PI)/10.0;
			float fAngleEnd		= fAngleStart + PI/5.0;

			if (iVertIndex % 2 == 0) 
			{
				glColor4f( r/255.0, g/255.0, b/255.0, alfa*2);
				glVertex3f(center.x + outerRadius*cos(fAngleStart)/STP, center.y + outerRadius*sin(fAngleStart), 0.0);
				glVertex3f(center.x + innerRadius*cos(fAngleEnd)/STP, center.y + innerRadius*sin(fAngleEnd), 0.0);
			} 
			else 
			{
				glColor4f( r/255.0, g/255.0, b/255.0, alfa*2);
				glVertex3f(center.x + innerRadius*cos(fAngleStart)/STP, center.y + innerRadius*sin(fAngleStart), 0.0);
				glVertex3f(center.x + outerRadius*cos(fAngleEnd)/STP, center.y + outerRadius*sin(fAngleEnd), 0.0);
			}
		}
	glEnd();
}

Star::~Star(void)
{
}

/*!
 * Copies bytes from a source memory area to a destination memory area,
 * where both areas may not overlap.
 * @param[in]  in  Current stream
 * @param[in]  star    Object to copy into
 */
istream& operator>>(istream& in, Star& star)
{
	int x, y;
	in>>star.center.x>>star.center.y>>star.center.z;
	return in;
}

/*!
* Separates the drawing canvas in squares of 0.1 x 0.1 and then creates a Point2D 
* with random coordinates inside that triangle
* All points are added to the *vect* vector
*/
void Star::generateRandomStars(vector<Point2D<double>> &vect) 
{
	srand(time(0));
	double x, y;
    double rand1, rand2;
    int step = 20;

	for(double i = -100.0; i <= 100.0; i+= step) 
	{
		for(double j = -100.0; j <= 100.0; j+= step) 
		{
			rand1 = rand() % step + 1;
            rand2 = rand() % step + 1;
            x = i + rand1;
            y = j + rand2;
            x /= 10.0;
            y /= 10.0;
            if(x < (-10) || x > 10 || y < (-10) || y > 10) 
			{
				continue;
			}

			Point2D<double> temp(x/10, y/10);
			vect.push_back(temp);
		}
	}
}

/*!
* Has *vect* vector as parameter and draws all the points onto the canvas
* The drawing is done using the DrawCircle method in Moon
*/
void Star::drawRandomStars(vector<Point2D<double>> vect, double alfa) 
{
	glColor3f(255/255.0, 255/255.0, 255/255.0);
	for(int i=0; i < vect.size(); ++i) 
	{
		Moon::DrawCircle(rand() % 4 + 1, vect[i].getX(), vect[i].getY(), alfa*10);
	}
}
