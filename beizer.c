#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
    int gd=DETECT,gm;
    int n,i,j,k;
    int x[20],y[20];
    double t,b,xt,yt;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    printf("Enter number of control points: ");
    scanf("%d",&n);

    if(n<2 || n>10)
    {
        printf("Invalid number of points");
        getch();
        closegraph();
        return;
    }

    for(i=0;i<n;i++)
    {
        printf("Enter P%d (x y): ",i);
        scanf("%d%d",&x[i],&y[i]);
    }

    setcolor(WHITE);

    for(i=0;i<n-1;i++)
        line(x[i],y[i],x[i+1],y[i+1]);

    setcolor(YELLOW);

    for(t=0;t<=1;t+=0.001)
    {
        xt=0;
        yt=0;

        for(j=0;j<n;j++)
        {
            b=1;

            for(k=1;k<=j;k++)
                b=b*(n-k)/k;

            b=b*pow(t,j)*pow(1-t,n-1-j);

            xt=xt+b*x[j];
            yt=yt+b*y[j];
        }

        putpixel((int)xt,(int)yt,YELLOW);
    }

    getch();
    closegraph();
}