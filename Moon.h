#pragma once
#ifdef __unix || __unix__
 #include <GL/glut.h>
#else
 #include <glut.h>
#endif

class Moon
{
    public:
        static void drawMoon(double &initPos);
        friend void DrawCircle(double r,double cx,double cy);
};