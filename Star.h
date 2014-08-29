#pragma once
#include<iostream>
#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif


using namespace std;

class Star
{
	float fX, fY, outerRadius, innerRadius;
public:
	Star();
	Star(float fX, float fY, float outerRadius, float innerRadius);
	float getFX();
	float getFY();
	float getOuterRadius();
	float getInnerRadius();
	void draw(int r, int g, int b);
	~Star(void);

	friend istream& operator>>(istream& in, Star& star);
};
