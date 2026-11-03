#include<graphics.h>
#include<conio.h>

void main()
{
    int gd=DETECT,gm;

    int x1=100,y1=100,x2=200,y2=200;
    int tx=100,ty=50;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    rectangle(100,100,200,200);

    x1=x1+tx;
    y1=y1+ty;
    x2=x2+tx;
    y2=y2+ty;

    setcolor(RED);

    rectangle(x1,y1,x2,y2);

    while(getch()!=27);
    closegraph();
}