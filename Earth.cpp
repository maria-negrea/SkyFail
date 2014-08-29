#include "Earth.h"

void Earth::draw()
{
	/*vector<Point3D*> ctrlPoints;
	ctrlPoints.push_back(new Point3D(-0.3, -1, 0.0));
	ctrlPoints.push_back(new Point3D(0.4, -0.1, 0.0));
	ctrlPoints.push_back(new Point3D(1.2, -1.0, 0.0));*/

	GLfloat ctrlPoints[3][3] = {
		{-0.3, -1, 0.0}, {0.4, -0.1, 0.0}, {1.2, -1.0, 0.0} 
	};
	/*glClear (GL_COLOR_BUFFER_BIT);*/
    glColor3f (1.0, 1.0, 1.0);
	glPushMatrix();
	
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 3, &ctrlPoints[0][0]);
   glEnable(GL_MAP1_VERTEX_3);
   int i;

   glColor3f( 145/255.0 , 169/255.0, 99/255.0);
   glBegin(GL_QUADS);
      for (i = 0; i < 30; i++) 
	  {
		  glEvalCoord1f((GLfloat) i/30.0);
		  glEvalCoord1f((GLfloat) (i+1)/30.0);
		  glVertex3f((-0.3) + (1.5/30)*(i+1), -1.0, 0.0);
		  glVertex3f((-0.3) + (1.5/30)*(i)  , -1.0, 0.0);
	  }
   glEnd();

   glPopMatrix();
   glFlush();
}
