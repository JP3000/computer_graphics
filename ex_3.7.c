#include <graphics.h>

int main()
{
    int gd = DETECT, gm, x, y;
    initgraph(&gd, &gm, NULL);
    cleardevice();
    moveto(100, 40);
    linerel(40 ,0);
    x = getx();
    y = gety();
    moveto(x, y + 20);
    linerel(-40, 0);
    moverel(0, 20);
    linerel(40, 0);
    moverel(-20, 0);
    linerel(0, -40);
    getch();
    closegraph();
    return 0;
}


