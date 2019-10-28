#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#define FNX(x) (x_0 + x * s1)
#define FNY(y) (y_0 - y * s1)
#define f(x) x*x

void setup(void);
int x_0, y_0, MAXX, MAXY;
float s1;
int main()
{
    int xs, ys;
    float x, y, x1, y1, x2, y2, dx, i;
    setup();
    /*
    printf("Input x1, x2 and dx: ");
    scanf("%f, %f, %f", &x1, &x2, &dx);
    */
    x1 = -10, x2 = 10, dx = 0.01;
    cleardevice();
    setcolor(14);
    xs = FNX(x1); ys = FNY(0), moveto(xs - 10, ys);
    xs = FNX(x2); lineto(xs + 10, ys);
    xs = FNX(0); ys = FNY(0), moveto(xs, ys);
    xs = FNX(0); lineto(xs, ys - 300);
    x = x1; y = f(x); xs = FNX(x); ys = FNY(y); moveto(xs, ys);
    for(i = x1; i < x2; i += dx){
        x += dx; y = f(x); xs = FNX(x); ys = FNY(y); lineto(xs, ys);       
    }
    getch();
    restorecrtmode();
}
void setup(void)
{
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    MAXX = getmaxx();
    MAXY = getmaxy();
    x_0 = 300, y_0 = 300;
    s1 = 20;
    /*
    printf("Input Orgin<int>x_0, y_0: ");
    scanf("%d, %d", &x_0, &y_0);
    printf("Input Multiple: ");
    scanf("%f", &s1);
    setviewport(0, 0, MAXX, MAXY, 1);
    */
}
