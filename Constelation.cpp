#include<fstream>
#include "Constelation.h"

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

void Constelation::draw()
{
	initialize("StarsCoordinates.txt");
	

	glPushMatrix();
	glColor3f(153/255.0, 162/255.0, 196/255.0);
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

	for(int i=0;i<stars.size();i++)
	{
		stars[i].draw(255, 255, 255);
	}
	glPopMatrix();
	glFlush();

}

