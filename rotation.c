#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void main()
{
    int gd=DETECT,gm;

    int x1=100,y1=100;
    int x2=200,y2=100;
    int x3=200,y3=200;
    int x4=100,y4=200;

    int rx1,ry1,rx2,ry2,rx3,ry3,rx4,ry4;

    float angle,rad;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    printf("Enter Rotation Angle: ");
    scanf("%f",&angle);

    rad=angle*3.14159/180;

    rectangle(100,100,200,200);

    rx1=(int)(x1*cos(rad)-y1*sin(rad));
    ry1=(int)(x1*sin(rad)+y1*cos(rad));

    rx2=(int)(x2*cos(rad)-y2*sin(rad));
    ry2=(int)(x2*sin(rad)+y2*cos(rad));

    rx3=(int)(x3*cos(rad)-y3*sin(rad));
    ry3=(int)(x3*sin(rad)+y3*cos(rad));

    rx4=(int)(x4*cos(rad)-y4*sin(rad));
    ry4=(int)(x4*sin(rad)+y4*cos(rad));

    rx1+=250; ry1+=50;
    rx2+=250; ry2+=50;
    rx3+=250; ry3+=50;
    rx4+=250; ry4+=50;

    setcolor(RED);

    line(rx1,ry1,rx2,ry2);
    line(rx2,ry2,rx3,ry3);
    line(rx3,ry3,rx4,ry4);
    line(rx4,ry4,rx1,ry1);

    while(getch()!=27);
    closegraph();
}