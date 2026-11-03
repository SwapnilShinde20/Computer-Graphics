#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void main()
{
    int gd=DETECT,gm;

    int x1,y1,x2,y2;
    int cx=150,cy=150;

    float sx,sy;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    printf("Enter Scaling Factors: ");
    scanf("%f%f",&sx,&sy);

    rectangle(100,100,200,200);

    x1 = cx - 50*sx;
    y1 = cy - 50*sy;

    x2 = cx + 50*sx;
    y2 = cy + 50*sy;

    setcolor(RED);

    rectangle(x1,y1,x2,y2);

    while(getch()!=27);
    closegraph();
}