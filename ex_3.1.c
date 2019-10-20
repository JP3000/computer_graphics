#include <graphics.h>

int main()
{
    int gd = DETECT, gm, left = 100, top = 100, right = 200, bottom = 200, x = 300, y = 150, radius = 50;
    initgraph(&gd, &gm, NULL);
    bar3d(10, 20, 50, 80, 0, 0);
    delay(5000);
    closegraph();
    return 0;
}
