#include "Constelation.h"
#include "Earth.h"
#include "Moon.h"
#include "Point2D.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


double xPos = -0.8;
double yPos = -0.3;
double radius = 100;

vector<Point2D<double>> vect;

void generateRandomStars() {
	srand(time(0));
	double x, y;
	glBegin(GL_POINTS);
	for(double i = -1.0; i < 1.0; i+= 0.1) {
		for(double j = -1.0; j < 1.0; j+= 0.1) {
			x = i*10 + (rand() % (int)((i+0.1)*10 - i*10 + 10.0));
			y = j*10 + (rand() % (int)((j+0.1)*10 - j*10 + 10.0));
			if(x < (-10) || x > 10 || y < (-10) || y > 10) {
				continue;
			}
			Point2D<double> temp(x, y);
		}
	}
	glEnd();
}

void initialize()
{
	glutInitWindowSize(600,400);
	glutCreateWindow("Flags");
	glClearColor(70 / 255.0, 66 / 255.0, 101 / 255.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	generateRandomStars();
}
void draw() {
	glClear (GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	Moon::drawMoon(xPos, yPos, radius);
	Earth::draw();
	Constelation::draw();

	glFlush();
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv); 
	initialize();

	glutDisplayFunc(draw);

	glutMainLoop();

	return 0;
}