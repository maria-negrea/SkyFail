#pragma once
#include<vector>
#include "Star.h"
#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif


using namespace std;
/*! \brief Constellation class
 * Reads set of points from input file, adds them to a vector of points
 * and then draws the constellation onto the canvas
 *
 */
class Constelation
{
	
public:	
    /*!
    * A vector of Stars (containing the coordinates for each star to be drawn representing the Constellation)
    */
	vector<Star> stars;
	void initialize(char* fileName);
	void draw(double& r, double& g, double& b, double& alfa, bool drawLines);
};
