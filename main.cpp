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
double rE=145, gE=169, bE=99;
double rC=70, gC=66, bC=101;
//int rC=250, gC=250, bC=250;

double rD=70, gD=66, bD=101;
double alfa=0.0;


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
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClear (GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	drawRandomStars();
}
void draw() {
	glClearColor(rD / 255.0, gD / 255.0, bD / 255.0, 0.0);
	Moon::drawMoon(xPos, yPos, radius);
	
	Constelation cons;
	cons.draw(rC, gC, bC, alfa);
	rD-=0.005;
	gD-=0.005;
	bD-=0.005;
	cout<<rD<<" "<<gD<<" "<<bD<<endl;
	Earth::draw(rE , gE, bE);
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