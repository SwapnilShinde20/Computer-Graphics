#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int dx, dy, steps, i;
    float x, y, xinc, yinc;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter x1 y1: ");
    scanf("%d%d", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%d%d", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xinc = (float)dx / steps;
    yinc = (float)dy / steps;

    x = x1;
    y = y1;

    for(i = 0; i <= steps; i++)
    {
        putpixel((int)x, (int)y, WHITE);

        x = x + xinc;
        y = y + yinc;
    }

    getch();
    closegraph();
}