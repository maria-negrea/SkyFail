#pragma once
#include "Star.h"
#include<vector>

using namespace std;

class Constelation
{
	
public:	
	static const vector<Star> stars;
	static void initialize(char* fileName);
	static void draw();
};
