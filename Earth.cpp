#include "Earth.h"


/*!
* #Earth Draw method
* Uses a Bezier curve which needs 3 control points to draw the contour of the Earth

* It is filled using quads 

* @param[in] r Red parameter
* @param[in] g Green parameter
* @param[in] b Blue parameter
*/
void Earth::draw(double& r, double& g, double& b)
{
	GLfloat ctrlPoints[3][3] = { {-0.3, -1, 0.0}, {0.4, -0.1, 0.0}, {1.2, -1.0, 0.0} };
	glColor3f (1.0, 1.0, 1.0);

	glPushMatrix();
	  glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 3, &ctrlPoints[0][0]);
	  glEnable(GL_MAP1_VERTEX_3);
	  int i;
      glColor4f( r/255.0 , g/255.0, b/255.0, 1.0);

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

   r+=0.005;
   g+=0.005;
   b+=0.005;

}
