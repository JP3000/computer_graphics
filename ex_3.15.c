#include <graphics.h>
#include <stdio.h>
int main()
{
    int i, j, c, x = 50, y = 50, k = 1;
    int gd = DETECT, gm;
    printf(" input color number.\n");
    scanf("%d", &c);
    initgraph(&gd, &gm, NULL);
    cleardevice();
    setbkcolor(11);
    setcolor(c);
    for(j = 1; j <= 2; j++)
    {
        for(i = 0; i < 4; i++)
        {
            setlinestyle(i, 0, k);
            rectangle(x, y, x + 210, y + 80);
            x = x + 110;
            y = y + 40;
        }
        k = 3;
        x = 50;
        y = 250;
    }
    getch();
    closegraph();
}

