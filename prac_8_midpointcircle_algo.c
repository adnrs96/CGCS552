#include<graphics.h>
#include<stdio.h>
#include<math.h>

int main()
{
   int gd = DETECT,gm;
   float xa,ya,r;

   printf("Enter the Center of circle\n");
   scanf("%f %f",&xa,&ya);
   printf("Enter the Radius of circle\n");
   scanf("%f",&r);
   initgraph(&gd,&gm,NULL);
   float pk = (5/4)-r;
   float x = 0,y=r;
   while(y>=x)
   {
     putpixel(x+xa,y+ya,WHITE);
     putpixel(y+xa,x+ya,WHITE);
     putpixel(x+xa,-(y)+ya,WHITE);
     putpixel(y+xa,-(x)+ya,WHITE);
     putpixel(-(x)+xa,y+ya,WHITE);
     putpixel(-(y)+xa,x+ya,WHITE);
     putpixel(-(x)+xa,-(y)+ya,WHITE);
     putpixel(-(y)+xa,-(x)+ya,WHITE);
     if(pk<0)
     {
       x+=1;
       pk=pk+2*x+1;
     }
     else
     {
       x+=1;
       y-=1;
       pk=pk+2*x+1-2*y;
     }
   }

   delay(5000);
   closegraph();
   return 0;
}
