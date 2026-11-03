#include<stdio.h>
#include<conio.h>
#include<graphics.h>

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

#define XMIN 150
#define YMIN 100
#define XMAX 450
#define YMAX 350

int code(float x,float y)
{
    int c=0;

    if(x<XMIN)
        c=c|LEFT;

    if(x>XMAX)
        c=c|RIGHT;

    if(y<YMIN)
        c=c|BOTTOM;

    if(y>YMAX)
        c=c|TOP;

    return c;
}

void clip(float x1,float y1,float x2,float y2)
{
    int c1,c2,c,accept=0;
    float x,y;

    c1=code(x1,y1);
    c2=code(x2,y2);

    while(1)
    {
        if((c1|c2)==0)
        {
            accept=1;
            break;
        }

        if(c1&c2)
            break;

        if(c1!=0)
            c=c1;
        else
            c=c2;

        if(c&TOP)
        {
            x=x1+(x2-x1)*(YMAX-y1)/(y2-y1);
            y=YMAX;
        }
        else if(c&BOTTOM)
        {
            x=x1+(x2-x1)*(YMIN-y1)/(y2-y1);
            y=YMIN;
        }
        else if(c&RIGHT)
        {
            y=y1+(y2-y1)*(XMAX-x1)/(x2-x1);
            x=XMAX;
        }
        else
        {
            y=y1+(y2-y1)*(XMIN-x1)/(x2-x1);
            x=XMIN;
        }

        if(c==c1)
        {
            x1=x;
            y1=y;
            c1=code(x1,y1);
        }
        else
        {
            x2=x;
            y2=y;
            c2=code(x2,y2);
        }
    }

    if(accept)
    {
        setcolor(GREEN);
        line(x1,y1,x2,y2);
    }
}

void main()
{
    int gd=DETECT,gm;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    /* CASE 1 : FULLY OUTSIDE */

    setcolor(WHITE);
    rectangle(XMIN,YMIN,XMAX,YMAX);

    setcolor(RED);
    line(50,300,100,150);

    outtextxy(50,30,"CASE 1 - FULLY OUTSIDE");
    outtextxy(50,450,"Line Rejected");

    while(getch()!=27);
    cleardevice();

    /* CASE 2 : FULLY INSIDE */

    setcolor(WHITE);
    rectangle(XMIN,YMIN,XMAX,YMAX);

    setcolor(RED);
    line(200,300,400,150);

    outtextxy(50,30,"CASE 2 - FULLY INSIDE");
    outtextxy(50,450,"Line Accepted");

    while(getch()!=27);
    cleardevice();

    /* CASE 3 : PARTIALLY CLIPPED */

    setcolor(WHITE);
    rectangle(XMIN,YMIN,XMAX,YMAX);

    setcolor(RED);
    line(80,320,500,130);

    outtextxy(50,30,"CASE 3 - PARTIALLY CLIPPED");
    outtextxy(50,450,"BEFORE CLIPPING - Press any key");

    while(getch()!=27);
    cleardevice();

    setcolor(WHITE);
    rectangle(XMIN,YMIN,XMAX,YMAX);

    /* AFTER CLIPPING */

    clip(80,320,500,130);

    outtextxy(50,30,"CASE 3 - PARTIALLY CLIPPED");
    outtextxy(50,450,"AFTER CLIPPING - GREEN LINE");

    while(getch()!=27);

    closegraph();
}