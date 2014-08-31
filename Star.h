#pragma once
#include<iostream>
#include "Point3D.h"
#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif


using namespace std;

class Star
{
	float outerRadius, innerRadius;	
public:
	Star();
	Point3D center;
	float getOuterRadius();
	float getInnerRadius();
	void draw(int r, int g, int b);
	~Star(void);

	friend istream& operator>>(istream& in, Star& star);
};
