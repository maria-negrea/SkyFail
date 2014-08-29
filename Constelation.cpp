#include "Constelation.h"
#include<fstream>

void Constelation::initialize(char* fileName)
{
	ifstream file(fileName);
	while(!file.eof())
	{
		Star star;
		file>>star;
		stars.push_back(star);
	}

	file.close();

}

void Constelation::draw()
{
	initialize("StarsCoordinates.txt");
	for(int i=0;i<stars.size();i++)
	{
		stars[i].draw(255, 252, 230);
	}
}

