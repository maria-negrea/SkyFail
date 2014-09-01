/**
\mainpage Constellation drawing 

 * Maria Negrea & Catalin Ionescu

 * 29 / 08 / 2014 -> 01/ 09/ 2014

 * This project represents a scene involving the Orion constellation during the timelapse of a night.

 * We are using the Glut Library for accesing drawing methods in OpenGL.
 
 * In order to build this project under Windows, one must use the Visual Studio suite (v.2008 recommended).
 * To run it under Linux (tested on Ubuntu), we provided a Make file runnable using *make* command.
 * 
 */

#include "Constelation.h"
#include "Earth.h"
#include "Moon.h"
#include "Point2D.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdio.h>

#ifdef __unix || __unix__
 #include <unistd.h>
#else
	#include <windows.h>
#endif

using namespace std;

double xPos = -1.0;
double yPos = -1.0;
double radius = 100;
double rE=79.0, gE=100.0, bE=60.0;
double rC=255.0, gC=242.0, bC=151.0;
double rD=70, gD=66, bD=101;
double alfa=0.0;
vector<Point2D<double>> vect;

void initialize();
void draw();


int main(int argc, char **argv)
{
	glutInit(&argc, argv); 
	initialize();

	glutDisplayFunc(draw);

	glutMainLoop();

	return 0;
}

/*!
* Initializes Glut and generated random points to populate * vect *
*/

void initialize()
{
	glutInitWindowSize(600,400);
	glutCreateWindow("Flags");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	Star::generateRandomStars(vect);
}

/*!
* The main draw function has: 
* draw stars (which has positions assigned from *initialize*)
* drawMoon (with initial coordinates)
* draw earth and constellation
*/

void draw() 
{
	glClear (GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(rD / 255.0, gD / 255.0, bD / 255.0, 0.0);

	Moon::drawMoon(xPos, yPos, radius);

	Constelation cons;
	if(xPos>0.9 && yPos>0.9)
	{
		cons.draw(rC, gC, bC, alfa, true);
	}
	else
	{
		cons.draw(rC, gC, bC, alfa, false);
	}

	Star::drawRandomStars(vect, alfa);

	Earth::draw(rE , gE, bE);	
	
	#ifdef __unix || __unix__
		usleep(10*1000);
	#else
		Sleep(10);
	#endif
	
	rD-=0.05;
	gD-=0.05;
	bD-=0.05;

	if(xPos > 1.3) 
	{
		rE=145.0, gE=169.0, bE=99.0;
		rC=70.0, gC=66.0, bC=101.0;
		rD=70, gD=66, bD=101;
		alfa=0.0;
	}
	
	glFlush();
	glutPostRedisplay();
}