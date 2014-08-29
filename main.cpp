#include "Earth.h"
#include<math.h>

double const PI = 3.14159;
double initPos = -0.8;

void initialize()
{
	glutInitWindowSize(600,400);
	glutCreateWindow("Flags");
	glClearColor(70 / 255.0, 66 / 255.0, 101 / 255.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0.0, 600.0, 400.0, 0.0, 0.0, 1.0);
}

//void reshape(int x, int y)
//{
//	if (y == 0 || x == 0) return;   
//	glMatrixMode(GL_PROJECTION);  
//	glLoadIdentity(); 
//	gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
//	glMatrixMode(GL_MODELVIEW);
//	glViewport(0,0,x,y);
//}

void DrawCircle(double r,double cx,double cy)
{
	double w = 600.0, h = 400.0;
	glBegin(GL_POLYGON);
		glVertex3f(cx,cy,0.0);

		for(double t = 0; t<PI*2;t+=0.2)
		{
			glVertex3f(cx+r/w*cos(t),cy+r/h*sin(t),0.0);
		}
		glVertex3f(cx+r/w*cos(0.0),cy+r/h*sin(0.0),0.0);
	glEnd();
}

void draw() {
	// draw moon
	glClear (GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();
		glColor3f( 255/255.0 , 255/255.0, 99/255.0);
		DrawCircle(100.0, -0.3, initPos);
	glPopMatrix();

	Earth::draw();

	initPos += 0.00001;
	if(initPos > 1.2)
		initPos = -1.2;
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