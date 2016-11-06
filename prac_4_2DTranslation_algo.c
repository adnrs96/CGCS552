#include<graphics.h>
#include<stdio.h>
#include<math.h>

#define PI 3.14159265

int main()
{
   int gd = DETECT,gm;

   float xa,ya,xb,yb,xao,yao,xbo,ybo;

   printf("Translation in 2D space\n");
   printf("Enter the starting point\n");
   scanf("%f %f",&xa,&ya);
   printf("Enter the ending point\n");
   scanf("%f %f",&xb,&yb);
   xao=xa,yao=ya,xbo=xb,ybo=yb;
   int ox,oy;
   printf("Enter new coordinates for Translation origin\n");
   scanf("%d %d",&ox,&oy);
   xa=xa+ox;
   xb=xb+ox;
   ya=ya+oy;
   yb=yb+oy;

   initgraph(&gd,&gm,NULL);
   line(xa,ya,xb,yb);
   setlinestyle(DASHED_LINE,0,THICK_WIDTH);
   line(xao,yao,xbo,ybo);
   delay(5000);
   closegraph();
   return 0;
}
