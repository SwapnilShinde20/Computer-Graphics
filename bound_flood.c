#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void boundaryFill4(int x, int y, int fillColor, int boundaryColor)
{
    int currentColor;
    currentColor = getpixel(x, y);

    if(currentColor != boundaryColor &&
        currentColor != fillColor)
    {
        putpixel(x, y, fillColor);

        boundaryFill4(x + 1, y, fillColor, boundaryColor);
        boundaryFill4(x - 1, y, fillColor, boundaryColor);
        boundaryFill4(x, y + 1, fillColor, boundaryColor);
        boundaryFill4(x, y - 1, fillColor, boundaryColor);
    }
}

void boundaryFill8(int x, int y, int fillColor, int boundaryColor)
{
    int currentColor;
    currentColor = getpixel(x, y);

    if(currentColor != boundaryColor &&
       currentColor != fillColor)
    {
        putpixel(x, y, fillColor);

        boundaryFill8(x + 1, y, fillColor, boundaryColor);
        boundaryFill8(x - 1, y, fillColor, boundaryColor);
        boundaryFill8(x, y + 1, fillColor, boundaryColor);
        boundaryFill8(x, y - 1, fillColor, boundaryColor);

        boundaryFill8(x + 1, y + 1, fillColor, boundaryColor);
        boundaryFill8(x - 1, y + 1, fillColor, boundaryColor);
        boundaryFill8(x + 1, y - 1, fillColor, boundaryColor);
        boundaryFill8(x - 1, y - 1, fillColor, boundaryColor);
    }
}

void floodFill4(int x, int y, int oldColor, int newColor)
{
    int currentColor;
    currentColor = getpixel(x, y);

    if(currentColor == oldColor)
    {
        putpixel(x, y, newColor);

        floodFill4(x + 1, y, oldColor, newColor);
        floodFill4(x - 1, y, oldColor, newColor);
        floodFill4(x, y + 1, oldColor, newColor);
        floodFill4(x, y - 1, oldColor, newColor);
    }
}

void floodFill8(int x, int y, int oldColor, int newColor)
{
    int currentColor;
    currentColor = getpixel(x, y);

    if(currentColor == oldColor)
    {
        putpixel(x, y, newColor);

        floodFill8(x + 1, y, oldColor, newColor);
        floodFill8(x - 1, y, oldColor, newColor);
        floodFill8(x, y + 1, oldColor, newColor);
        floodFill8(x, y - 1, oldColor, newColor);

        floodFill8(x + 1, y + 1, oldColor, newColor);
        floodFill8(x - 1, y + 1, oldColor, newColor);
        floodFill8(x + 1, y - 1, oldColor, newColor);
        floodFill8(x - 1, y - 1, oldColor, newColor);
    }
}

void main()
{
    int gd=DETECT,gm;

    initgraph(&gd,&gm,"C:\\TC\\BGI");

    cleardevice();

    setcolor(WHITE);
    outtextxy(200,40,"RECTANGLE FILL TEST");

    setlinestyle(SOLID_LINE,0,THICK_WIDTH);

    rectangle(100,100,140,130);

    // TEST ONLY ONE AT A TIME

    boundaryFill4(120,115,RED,WHITE);

    // boundaryFill8(120,115,RED,WHITE);

    // floodFill4(120,115,BLACK,RED);

    // floodFill8(120,115,BLACK,RED);

    getch();
    closegraph();
}