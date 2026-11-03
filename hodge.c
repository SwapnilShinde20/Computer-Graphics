#include<stdio.h>
#include<conio.h>
#include<graphics.h>

float x[20],y[20],nx[20],ny[20];
float xmin=150,ymin=100,xmax=450,ymax=350;
float ix,iy;
int n;

int inside(float x,float y,int edge)
{
    if(edge==0) return x>=xmin;  // Left
    if(edge==1) return x<=xmax;  // Right
    if(edge==2) return y>=ymin;  // Bottom
    if(edge==3) return y<=ymax;  // Top
    return 0;
}

void intersection(float x1,float y1,float x2,float y2,int edge)
{
    if(edge==0 || edge==1)
    {
        ix=(edge==0)?xmin:xmax;
        iy=y1+(y2-y1)*(ix-x1)/(x2-x1);
    }
    else
    {
        iy=(edge==2)?ymin:ymax;
        ix=x1+(x2-x1)*(iy-y1)/(y2-y1);
    }
}

void clip(int edge)
{
    int i,j=0;
    float sx,sy,ex,ey;

    sx=x[n-1];
    sy=y[n-1];

    for(i=0;i<n;i++)
    {
        ex=x[i];
        ey=y[i];

        if(inside(sx,sy,edge) && inside(ex,ey,edge))
        {
            nx[j]=ex;
            ny[j++]=ey;
        }
        else if(inside(sx,sy,edge) && !inside(ex,ey,edge))
        {
            intersection(sx,sy,ex,ey,edge);
            nx[j]=ix;
            ny[j++]=iy;
        }
        else if(!inside(sx,sy,edge) && inside(ex,ey,edge))
        {
            intersection(sx,sy,ex,ey,edge);
            nx[j]=ix;
            ny[j++]=iy;

            nx[j]=ex;
            ny[j++]=ey;
        }

        sx=ex;
        sy=ey;
    }

    n=j;

    for(i=0;i<n;i++)
    {
        x[i]=nx[i];
        y[i]=ny[i];
    }
}

void drawPolygon()
{
    int i;

    for(i=0;i<n;i++)
        line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
}

void main()
{
    int gd=DETECT,gm,i;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    n=5;

    x[0]=100; y[0]=150;
    x[1]=300; y[1]=50;
    x[2]=500; y[2]=150;
    x[3]=400; y[3]=400;
    x[4]=180; y[4]=300;

    setcolor(WHITE);
    rectangle(xmin,ymin,xmax,ymax);

    setcolor(RED);
    drawPolygon();

    outtextxy(200,50,"BEFORE CLIPPING");
    getch();

    cleardevice();

    /* CLIP AGAINST FOUR EDGES */

    for(i=0;i<4;i++)
        clip(i);

    setcolor(WHITE);
    rectangle(xmin,ymin,xmax,ymax);

    setcolor(GREEN);
    drawPolygon();

    outtextxy(200,50,"AFTER CLIPPING");

    getch();
    closegraph();
}