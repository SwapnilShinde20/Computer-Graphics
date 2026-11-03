#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

#define PI 3.14159

void triangle(int x1, int y1, int x2, int y2,
              int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main()
{
    int gd = DETECT, gm;
    int ch;

    /* Original Triangle */
    int x1 = 350, y1 = 100;
    int x2 = 450, y2 = 100;
    int x3 = 400, y3 = 50;

    int nx1, ny1, nx2, ny2, nx3, ny3;
    float angle, sh;

    /* Origin */
    int ox = 300;
    int oy = 175;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("\n\nEXPERIMENT 5");
    printf("\nReflection and Shearing Transformation");

    printf("\n\n1. Reflection");
    printf("\n2. X-Shearing");
    printf("\n3. Y-Shearing");

    printf("\n\nEnter choice: ");
    scanf("%d", &ch);

    cleardevice();

    setcolor(DARKGRAY);
    line(0, oy, 639, oy);
    line(ox, 0, ox, 349);

    /* REFLECTION */

    if(ch == 1)
    {
        /* Original */
        setcolor(WHITE);
        triangle(x1,y1,x2,y2,x3,y3);

        /* Reflection about X-axis */
        nx1 = x1;
        ny1 = 2 * oy - y1;

        nx2 = x2;
        ny2 = 2 * oy - y2;

        nx3 = x3;
        ny3 = 2 * oy - y3;

        setcolor(RED);
        triangle(nx1,ny1,nx2,ny2,nx3,ny3);

        /* Reflection about Y-axis */
        nx1 = 2 * ox - x1;
        ny1 = y1;

        nx2 = 2 * ox - x2;
        ny2 = y2;

        nx3 = 2 * ox - x3;
        ny3 = y3;

        setcolor(GREEN);
        triangle(nx1,ny1,nx2,ny2,nx3,ny3);

        /* Reflection about Origin */
        nx1 = 2 * ox - x1;
        ny1 = 2 * oy - y1;

        nx2 = 2 * ox - x2;
        ny2 = 2 * oy - y2;

        nx3 = 2 * ox - x3;
        ny3 = 2 * oy - y3;

        setcolor(YELLOW);
        triangle(nx1,ny1,nx2,ny2,nx3,ny3);

        /* Reflection about Y = X */
        nx1 = ox + (oy - y1);
        ny1 = oy + (ox - x1);

        nx2 = ox + (oy - y2);
        ny2 = oy + (ox - x2);

        nx3 = ox + (oy - y3);
        ny3 = oy + (ox - x3);

        setcolor(LIGHTBLUE);
        triangle(nx1,ny1,nx2,ny2,nx3,ny3);

        printf("\n\nREFLECTION");
        printf("\nWHITE    = Original");
        printf("\nRED      = X-axis Reflection");
        printf("\nGREEN    = Y-axis Reflection");
        printf("\nYELLOW   = Origin Reflection");
        printf("\nBLUE     = Y = X Reflection");

        printf("\n\nPress ESC to exit.");
        while(getch() != 27);
    }

    /* X-SHEARING */

    else if(ch == 2)
    {
        printf("\nEnter tilt angle in degrees: ");
        scanf("%f", &angle);

        sh = tan(angle * PI / 180);

        /* Original */
        setcolor(WHITE);
        triangle(x1,y1,x2,y2,x3,y3);

        /* X-Shear */
        nx1 = x1 + sh * (oy - y1);
        ny1 = y1;

        nx2 = x2 + sh * (oy - y2);
        ny2 = y2;

        nx3 = x3 + sh * (oy - y3);
        ny3 = y3;

        setcolor(RED);
        triangle(nx1,ny1,nx2,ny2,nx3,ny3);

        printf("\n\nX-SHEARING");
        printf("\nTilt angle = %.2f degrees", angle);
        printf("\nShear factor = %.2f", sh);

        printf("\n\nWHITE = Original");
        printf("\nRED = X-Sheared");

        printf("\n\nPress ESC to exit.");
        while(getch() != 27);
    }

    /* Y-SHEARING */

    else if(ch == 3)
    {
        printf("\nEnter tilt angle in degrees: ");
        scanf("%f", &angle);

        sh = tan(angle * PI / 180);

        /* Original */
        setcolor(WHITE);
        triangle(x1,y1,x2,y2,x3,y3);

        /* Y-Shear */
        nx1 = x1;
        ny1 = y1 - sh * (x1 - ox);

        nx2 = x2;
        ny2 = y2 - sh * (x2 - ox);

        nx3 = x3;
        ny3 = y3 - sh * (x3 - ox);

        setcolor(GREEN);
        triangle(nx1,ny1,nx2,ny2,nx3,ny3);

        printf("\n\nY-SHEARING");
        printf("\nTilt angle = %.2f degrees", angle);
        printf("\nShear factor = %.2f", sh);

        printf("\n\nWHITE = Original");
        printf("\nGREEN = Y-Sheared");

        printf("\n\nPress ESC to exit.");
        while(getch() != 27);
    }

    else
    {
        printf("\nInvalid choice!");
        while(getch() != 27);
    }

    closegraph();
    return 0;
}