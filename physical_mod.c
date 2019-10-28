#include <graphics.h>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926
int main()
{
    float theta, x0, y0, x1, y1, x2, y2, r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    x0 = 0, y0 = 0; r = 100;
    for(theta = 0; theta < 360; theta++)
    {
        x1 = x0 + r*cos(theta*PI/180.0);
        y1 = y0 + r*sin(theta*PI/180.0);
        setcolor(RED);
        line(x0, y0, x1, y1);
        delay(2000);
        cleardevice();
    }

} 
