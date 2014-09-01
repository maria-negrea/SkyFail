/**
\mainpage Constellation drawing example

 * Maria Negrea & Catalin Ionescu

 * 1 / 9 / 2014

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
double rE=145.0, gE=169.0, bE=99.0;
double rC=70.0, gC=66.0, bC=101.0;

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

void draw() {
	glClearColor(rD / 255.0, gD / 255.0, bD / 255.0, 0.0);
	
	Earth::draw(rE , gE, bE);

	Moon::drawMoon(xPos, yPos, radius);
	
	Earth::draw(rE , gE, bE);
	
	Constelation cons;
	cons.draw(rC, gC, bC, alfa);
	
	Earth::draw(rE , gE, bE);
	
	Star::drawRandomStars(vect);
	
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