#pragma once
#include "Point3D.h"
#include<vector>
#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif

using namespace std;
class Earth
{
public:
	static void draw(double& r, double& g, double& b);
};
