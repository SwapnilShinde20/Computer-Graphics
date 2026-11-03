#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int dx, dy, p, x, y;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter x1 y1: ");
    scanf("%d%d", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%d%d", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    p = 2 * dy - dx;

    x = x1;
    y = y1;

    while(x <= x2)
    {
        putpixel(x, y, WHITE);

        if(p < 0)
            p = p + 2 * dy;
        else
        {
            y = y + 1;
            p = p + 2 * (dy - dx);
        }

        x = x + 1;
    }

    getch();
    closegraph();
}