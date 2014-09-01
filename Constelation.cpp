#include<fstream>
#include "Constelation.h"

/*!
*
	* @param[in] fileName The name of the file to read star coordinates from
*/
void Constelation::initialize(char* fileName)
{
	ifstream file(fileName);
	while(!file.eof())
	{
		Star star;
		file>>star;
		stars.push_back(star);
	}

	file.close();

}

/*!
*	Constellation draw method
* It draws in several rounds due to multiple points being connected to more than one point
* At the end, it draws the stars using the Star.draw method
* @param[in] r Red parameter
* @param[in] g Green parameter
* @param[in] b Blue parameter
* @param[in] alfa The alpha parameter (transparency)
*/
void Constelation::draw(double& r, double& g, double& b, double& alfa)
{
	initialize("StarsCoordinates.txt");
	

	glPushMatrix();
	glColor4f(r/255.0, g/255.0, b/255.0, alfa);
	glBegin(GL_LINE_STRIP);
		for(int i=0;i<8;i++)
		{			
			glVertex3f(stars[i].center.x, stars[i].center.y, stars[i].center.z);
		}
		glVertex3f(stars[1].center.x, stars[1].center.y, stars[1].center.z);		
		
	glEnd();

	glBegin(GL_LINE_STRIP);
	for(int i=9;i<stars.size();i++)
		{			
			glVertex3f(stars[i].center.x, stars[i].center.y, stars[i].center.z);
		}

	glEnd();

	glBegin(GL_LINE_STRIP);			
		glVertex3f(stars[2].center.x, stars[2].center.y, stars[2].center.z);
		glVertex3f(stars[8].center.x, stars[8].center.y, stars[8].center.z);
		glVertex3f(stars[5].center.x, stars[5].center.y, stars[5].center.z);

	glEnd();

	glBegin(GL_LINE_STRIP);			
		glVertex3f(stars[6].center.x, stars[6].center.y, stars[6].center.z);
		glVertex3f(stars[12].center.x, stars[12].center.y, stars[12].center.z);

	glEnd();

	glColor4f(r/255.0, g/255.0, b/255.0, alfa);
	for(int i=0;i<stars.size();i++)
	{
		stars[i].draw(r, g, b, alfa);
	}
	glPopMatrix();
	glFlush();
	r+=0.1;
	g+=0.1;
	b+=0.1;

	if(alfa< 1.0)
	{
		alfa+=0.00005;
	}

}

