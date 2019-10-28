#include <graphics.h>
#include <math.h>
#include <stdio.h>
void DDALine(int x1, int y1, int x2, int y2);

int main()
{
    int gd = DETECT, gm;
    int bkcolor, midx, midy;
    initgraph(&gd, &gm, NULL);
    //DDALine(0, 0, 640, 480);
    setcolor(2);
    DDALine(160, 360, 540, 360);
    DDALine(240, 60, 240, 480);
    //DDALine(480, 360, 240, 120);
    DDALine(540, 420, 180, 60);

    setcolor(3);
    line(160, 420, 540, 420);
    line(300, 60, 300, 480);
    //line(480, 360, 240, 120);
    line(600, 540, 180, 120);


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
