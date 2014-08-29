#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Constelation.h"
#include "Earth.h"
#include "Moon.h"


using namespace std;


double xPos = -0.8;
double yPos = -0.3;
double radius = 100;


void drawRandomStars() {
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
			glColor3f( 0/255.0 , 0/255.0, 0/255.0);
			glVertex3f(x, y, 0.0);
			cout<<x/10.0<<" "<<y/10.0<<endl;
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
	glClear (GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	drawRandomStars();
}
void draw() {
	Moon::drawMoon(xPos, yPos, radius);
	Earth::draw();
	Constelation cons;
	cons.draw();

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