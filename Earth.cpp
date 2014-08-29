#include "Earth.h"

void Earth::draw()
{
	GLfloat ctrlPoints[3][3] = {
		{-0.3, -1, 0.0}, {0.4, -0.1, 0.0}, {1.2, -1.0, 0.0} 
	};
	glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
	//glPushMatrix();
	
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
		 /* glBegin(GL_QUADS);
			
		  glEnd();*/

	  }
   glEnd();
   ///* The following code displays the control points as dots. */
   //glPointSize(5.0);
   //glColor3f(1.0, 1.0, 0.0);
   //glBegin(GL_POINTS);
   //   for (i = 0; i < 4; i++) 
   //      glVertex3fv(&ctrlPoints[i][0]);
   //glEnd();
   
   glFlush();
}
