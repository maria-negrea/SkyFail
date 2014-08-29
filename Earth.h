#pragma once
#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif

class Earth
{
public:
	static void draw();
};
