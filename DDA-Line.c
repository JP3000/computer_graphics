#include <graphics.h>
#include <math.h>
#include <stdio.h>
void DDALine(int x1, int y1, int x2, int y2);

int main()
{
    int gd = DETECT, gm;
    int bkcolor, midx, midy;
    initgraph(&gd, &gm, NULL);
    DDALine(0, 100, 639, 479);
    getch();
    closegraph();
    return(0);
}

void DDALine(int x1, int y1, int x2, int y2)
{
    double dx, dy, e, x, y;
    int color;
    int i;
    dx = x2 - x1;
    dy = y2 - y1;
    e  = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    dx /= e;
    dy /= e;
    x = x1;
    y = y1;
    color = getcolor();
    for(i = 0; i <= e; i++)
    {
        putpixel((int)(x + 0.5), (int)(y + 0.5), color);
        x += dx;
        y += dy;
    }
}
