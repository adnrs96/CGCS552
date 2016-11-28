#include<graphics.h>
#include<stdio.h>
#include<math.h>

#define PI 3.14159265

int main()
{
   int gd = DETECT,gm;
   float xa,ya,xb,yb,xao,yao,xbo,ybo;
   printf("Rotation in 2D space\n");
   printf("Enter the starting point\n");
   scanf("%f %f",&xa,&ya);
   printf("Enter the ending point\n");
   scanf("%f %f",&xb,&yb);
   xao=xa,yao=ya,xbo=xb,ybo=yb;
   int rx,ry;
   double ang,val;
   printf("Enter coordinates for point about which should i rotate\n");
   scanf("%d %d",&rx,&ry);
   printf("Enter angle by which to rotate\n");
   scanf("%lf",&ang);
   xa=xa-rx;
   xb=xb-rx;
   ya=ya-ry;
   yb=yb-ry;
   val = PI / 180.0;
   ang=ang*val;
   float nxa=xa,nya=ya,nyb=yb,nxb=xb;
   xa = (nxa*cos(ang))-(nya*sin(ang));
   ya = (nxa*sin(ang))+(nya*cos(ang));
   xb = (nxb*cos(ang))-(nyb*sin(ang));
   yb = (nxb*sin(ang))+(nyb*cos(ang));
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
