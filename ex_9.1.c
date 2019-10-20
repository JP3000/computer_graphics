#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_SIZE 10
void draw_image();
void draw_stars();

int main()
{
    int gd = DETECT, gm;
    void *pt_addr;
    int x, y, maxx, maxy, midx, midy, I;
    unsigned int size;
    initgraph(&gd, &gm, NULL);
    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy / 2;
    x = 0;
    setcolor(YELLOW);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    outtextxy(midx, 400, "HELLO!");
    setcolor(RED);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    setcolor(LIGHTBLUE);
    for(I = 0; I < 13; I++)
    {
        ellipse(midx, midy, 0, 360, 100, 100 - 8*I);
        ellipse(midx, midy, 0, 360, 100 - 8*I, 100);
    }
    draw_image(x, y);
    size = imagesize(x , y-IMAGE_SIZE, x + (4 * IMAGE_SIZE), y + IMAGE_SIZE);
    pt_addr = malloc(size);
    getimage(x, y - IMAGE_SIZE, x + (4 * IMAGE_SIZE), y + IMAGE_SIZE, pt_addr);
    draw_stars();
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    rectangle(0, 0, maxx, maxy);
    while(!kbhit())
    {
        putimage(x, y - IMAGE_SIZE, pt_addr, XOR_PUT);
        x = x + 5;
        if(x >= maxx) x = 0;
        putimage(x, y - IMAGE_SIZE, pt_addr, XOR_PUT);
        delay(50);
    }
    free(pt_addr);
    closegraph();
}
void draw_image(int x, int y)
{
    moveto(x + 10, y);
    setcolor(14);
    setfillstyle(1, 4);
    linerel(-30, -20);
    moveto(x + 25, y);
    linerel(-50, 0);
    fillellipse(x + 13, y, 8, 8);
}
void draw_stars(void)
{
    int dotx, doty, h, w, I;
    int color, maxcolor;
    maxcolor = getmaxcolor();
    w = getmaxx();
    h = getmaxy();
    srand(2000);
    for(I = 0; I < 5000; I++)
    {
        dotx = I + random(w - 1);
        dotx = I + random(h - 1);
        color = random(maxcolor);
        putpixel(dotx, doty, color);
    }
}
