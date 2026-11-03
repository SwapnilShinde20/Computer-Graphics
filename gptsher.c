#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void triangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
    line(320+x1,240-y1,320+x2,240-y2);
    line(320+x2,240-y2,320+x3,240-y3);
    line(320+x3,240-y3,320+x1,240-y1);
}

void main()
{
    int gd=DETECT,gm;
    int ch;

    int x1=50,y1=50;
    int x2=150,y2=50;
    int x3=100,y3=125;

    int nx1,ny1,nx2,ny2,nx3,ny3;

    float shx,shy;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    printf("\n1. Reflection");
    printf("\n2. X-Shearing");
    printf("\n3. Y-Shearing");

    printf("\nEnter choice: ");
    scanf("%d",&ch);

    cleardevice();

    /* REFLECTION */

    if(ch==1)
    {
        setcolor(WHITE);
        triangle(x1,y1,x2,y2,x3,y3);

        /* X-axis Reflection */

        nx1=x1;
        ny1=-y1;

        nx2=x2;
        ny2=-y2;

        nx3=x3;
        ny3=-y3;

        setcolor(RED);
        triangle(nx1,ny1,nx2,ny2,nx3,ny3);

        /* Y-axis Reflection */

        nx1=-x1;
        ny1=y1;

        nx2=-x2;
        ny2=y2;

        nx3=-x3;
        ny3=y3;

        setcolor(GREEN);
        triangle(nx1,ny1,nx2,ny2,nx3,ny3);

        /* Origin Reflection */

        nx1=-x1;
        ny1=-y1;

        nx2=-x2;
        ny2=-y2;

        nx3=-x3;
        ny3=-y3;

        setcolor(YELLOW);
        triangle(nx1,ny1,nx2,ny2,nx3,ny3);

        /* Y = X Reflection */

        nx1=y1;
        ny1=x1;

        nx2=y2;
        ny2=x2;

        nx3=y3;
        ny3=x3;

        setcolor(LIGHTBLUE);
        triangle(nx1,ny1,nx2,ny2,nx3,ny3);
    }

    /* X-SHEARING */

    else if(ch==2)
    {
        printf("\nEnter X Shear Factor: ");
        scanf("%f",&shx);

        setcolor(WHITE);
        triangle(x1,y1,x2,y2,x3,y3);

        nx1=(int)(x1+shx*y1);
        ny1=y1;

        nx2=(int)(x2+shx*y2);
        ny2=y2;

        nx3=(int)(x3+shx*y3);
        ny3=y3;

        setcolor(RED);
        triangle(nx1,ny1,nx2,ny2,nx3,ny3);
    }

    /* Y-SHEARING */

    else if(ch==3)
    {
        printf("\nEnter Y Shear Factor: ");
        scanf("%f",&shy);

        setcolor(WHITE);
        triangle(x1,y1,x2,y2,x3,y3);

        nx1=x1;
        ny1=(int)(y1+shy*x1);

        nx2=x2;
        ny2=(int)(y2+shy*x2);

        nx3=x3;
        ny3=(int)(y3+shy*x3);

        setcolor(GREEN);
        triangle(nx1,ny1,nx2,ny2,nx3,ny3);
    }

    else
    {
        printf("\nInvalid Choice!");
    }

    getch();
    closegraph();
}