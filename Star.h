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
    /*!
    *   The center point of the star object
    */
	Point3D center;
    /*!
    *   Getter for outerRadius private member
    */
	float getOuterRadius();
	/*!
    *   Getter for innerRadius private member
    */
    float getInnerRadius();
	void draw(int r, int g, int b, double alfa);

    static void drawRandomStars(vector<Point2D<double>> vect, double alfa);
    static void generateRandomStars(vector<Point2D<double>> &vect);
	
    ~Star(void);
	friend istream& operator>>(istream& in, Star& star);
};
