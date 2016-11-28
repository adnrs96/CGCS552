#include<graphics.h>
#include<stdio.h>
#include<math.h>

#define PI 3.14159265

int main()
{
   int gd = DETECT,gm;
   float xa,ya,xb,yb,xao,yao,xbo,ybo;
   printf("Scaling in 2D space\n");
   printf("Enter the starting point\n");
   scanf("%f %f",&xa,&ya);
   printf("Enter the ending point\n");
   scanf("%f %f",&xb,&yb);
   xao=xa,yao=ya,xbo=xb,ybo=yb;
   int sx,sy;
   printf("Enter scaling factors for x and y directions\n");
   scanf("%d %d",&sx,&sy);
   int rx,ry;
   printf("Enter coordinates for point about which should i Scale\n");
   scanf("%d %d",&rx,&ry);
   xa=xa-rx;
   xb=xb-rx;
   ya=ya-ry;
   yb=yb-ry;

   xa=xa*sx;
   xb=xb*sx;
   ya=ya*sy;
   yb=yb*sy;

   xa=xa+rx;
   xb=xb+rx;
   ya=ya+ry;
   yb=yb+ry;
   initgraph(&gd,&gm,NULL);
   line(xa,ya,xb,yb);
   setlinestyle(DASHED_LINE,0,THICK_WIDTH);
   line(xao,yao,xbo,ybo);
   delay(5000);
   closegraph();
   return 0;
}
