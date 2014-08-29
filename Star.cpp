#include "Star.h"
#include<math.h>

Star::Star()
{
	outerRadius=0.1;
	innerRadius=0.05;
}
Star::Star(float fX, float fY, float outerRadius, float innerRadius)
{
	this->fX=fX;
	this->fY=fY;
	this->outerRadius=outerRadius;
	this->innerRadius=innerRadius;
}

float Star::getFX()
{
	return this->fX;
}

float Star::getFY()
{
	return this->fY;
}

float Star:: getOuterRadius()
{
	return this->outerRadius;
}

float Star:: getInnerRadius()
{
	return this->innerRadius;
}

void Star::draw(int r, int g, int b)
{
	glColor3f( r/255.0, g/255.0, b/255.0);
	const float PI = 3.1415926535897932384626433832795;
	const float STP = 1.0;
	
	glBegin(GL_TRIANGLE_FAN);
		
		glVertex3f(fX, fY, 0.0);
		
		for (int iVertIndex = 0; iVertIndex < 10; ++iVertIndex) 
		{
			float fAngleStart	= PI/2.0 + (iVertIndex*2.0*PI)/10.0;
			float fAngleEnd		= fAngleStart + PI/5.0;
			if (iVertIndex % 2 == 0) 
			{
				glVertex3f(fX + outerRadius*cos(fAngleStart)/STP, fY + outerRadius*sin(fAngleStart), 0.0);
				glVertex3f(fX + innerRadius*cos(fAngleEnd)/STP, fY + innerRadius*sin(fAngleEnd), 0.0);
			} 
			else 
			{
				glVertex3f(fX + innerRadius*cos(fAngleStart)/STP, fY + innerRadius*sin(fAngleStart), 0.0);
				glVertex3f(fX + outerRadius*cos(fAngleEnd)/STP, fY + outerRadius*sin(fAngleEnd), 0.0);
			}
		}
	glEnd();
}

Star::~Star(void)
{
}

istream& operator>>(istream& in, Star& star)
{
	return in>>star.fX>>star.fY;
}
