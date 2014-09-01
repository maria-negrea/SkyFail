#include<math.h>
#include "Star.h"


Star::Star()
{
	outerRadius=0.03;
	innerRadius=0.015;
}

float Star:: getOuterRadius()
{
	return this->outerRadius;
}

float Star:: getInnerRadius()
{
	return this->innerRadius;
}

void Star::draw(int r, int g, int b, double alfa)
{
	
	const float PI = 3.1415926535897932384626433832795;
	const float STP = 1.0;
	
	glBegin(GL_TRIANGLE_FAN);
		
		glColor4f( r/255.0, g/255.0, b/255.0, alfa);
		glVertex3f(center.x, center.y, 0.0);
		
		for (int iVertIndex = 0; iVertIndex < 10; ++iVertIndex) 
		{
			float fAngleStart	= PI/2.0 + (iVertIndex*2.0*PI)/10.0;
			float fAngleEnd		= fAngleStart + PI/5.0;
			if (iVertIndex % 2 == 0) 
			{
				glColor4f( r/255.0, g/255.0, b/255.0, alfa/2);
				glVertex3f(center.x + outerRadius*cos(fAngleStart)/STP, center.y + outerRadius*sin(fAngleStart), 0.0);
				glVertex3f(center.x + innerRadius*cos(fAngleEnd)/STP, center.y + innerRadius*sin(fAngleEnd), 0.0);
			} 
			else 
			{
				glColor4f( r/255.0, g/255.0, b/255.0, alfa/2);
				glVertex3f(center.x + innerRadius*cos(fAngleStart)/STP, center.y + innerRadius*sin(fAngleStart), 0.0);
				glVertex3f(center.x + outerRadius*cos(fAngleEnd)/STP, center.y + outerRadius*sin(fAngleEnd), 0.0);
			}
		}
	glEnd();
}

Star::~Star(void)
{
}

istream& operator>>(istream& in, Star& star)
{
	int x, y;
	in>>star.center.x>>star.center.y>>star.center.z;
	return in;
}
