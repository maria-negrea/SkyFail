#pragma once
#include <iostream>
#include <vector>
#include<ctime>
#include "Point2D.cpp"
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
	void draw(int r, int g, int b, double alfa);

    static void drawRandomStars(vector<Point2D<double>> vect);
    static void generateRandomStars(vector<Point2D<double>> &vect);
	
    ~Star(void);
	friend istream& operator>>(istream& in, Star& star);
};
