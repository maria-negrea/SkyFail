#include "Earth.h"
#include "Moon.h"
#include <iostream>

using namespace std;


double xPos = -0.8;
double yPos = -0.3;
double radius = 100;

void initialize()
{
	glutInitWindowSize(600,400);
	glutCreateWindow("Flags");
	glClearColor(70 / 255.0, 66 / 255.0, 101 / 255.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
void draw() {
	glClear (GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	Moon::drawMoon(xPos, yPos, radius);
	cout<<xPos<<" "<<yPos<<endl;
	Earth::draw();

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