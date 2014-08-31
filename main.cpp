#include "Constelation.h"
#include "Earth.h"
#include "Moon.h"
#include "Point2D.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unistd.h>

using namespace std;

double xPos = -1.0;
double yPos = -1.0;
double radius = 100;
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

/*
* Initializes Glut and generated random points to populate * vect *
*/

void initialize()
{
	glutInitWindowSize(600,400);
	glutCreateWindow("Flags");
	glClearColor(70 / 255.0, 66 / 255.0, 101 / 255.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	Star::generateRandomStars(vect);
}

/*
* The main draw function has: 
* draw stars (which has positions assigned from *initialize*)
* drawMoon (with initial coordinates)
* draw earth and constellation
*/

void draw() {
	glClear (GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	Moon::drawMoon(xPos, yPos, radius);
	
	Constelation cons;
	cons.draw();
	
	Earth::draw();
	
	Star::drawRandomStars(vect);

	usleep(2*1000);
	glFlush();
	glutPostRedisplay();
}