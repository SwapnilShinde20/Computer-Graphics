#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>

int main(){
    int gd = DETECT,gm;
    int x,y,r,p,xc,yc;

    printf("Hello");

    xc = 320;
    yc = 240;
    r = 100;

    x = 0, y = r;
    p = 1 - r;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    while(x <= y){

        putpixel(x+xc,y+yc,WHITE);
        putpixel(-x+xc, y+yc, WHITE);
        putpixel(x+xc, -y+yc, WHITE);
        putpixel(-x+xc, -y+yc, WHITE);

        putpixel(y+xc, x+yc, WHITE);
        putpixel(-y+xc, x+yc, WHITE);
        putpixel(y+xc, -x+yc, WHITE);
        putpixel(-y+xc, -x+yc, WHITE);

        x++;

        if(p<0){
            p = p + 2*x + 1;
        }
        else{
            y--;
            p = p + 2*x - 2*y + 1;
        }
    }

    while(getch()!=27);

    closegraph();
    return 0;
}