#include <graphics.h>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926
int main()
{
    double theta, x0, y0, x1, y1, x2, y2, r, l;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    x0 = 240, y0 = 240; r = 100; l = 173;
    /*
    square_l = l * l;
    square_r = r * r;
    square_sin = sin(theta) * sin(theta);
    */
    for(theta = 0; theta < 360; theta--)
    {
        setcolor(RED);
        circle(x0, y0, r);
       
        setcolor(GREEN);
        x1 = x0 + r*cos(theta*PI/180.0);
        y1 = y0 + r*sin(theta*PI/180.0);
    

        x2 = sqrt(l * l- r*r*sin(theta*PI/180.0)*sin(theta*PI/180.0)) + x1;
        y2 = y0;
        
        line(x0, y0, x1, y1);
        line(x1, y1, x2, y2);
        line(x2 - 50, y2, x2 + 50, y2);
        delay(100);
        cleardevice();
        //if(getch()) break;
    }
    closegraph();

} 
