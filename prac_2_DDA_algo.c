#include<graphics.h> 
#include<stdio.h>
int main()
{
   int gd = DETECT,gm;
   int xa,ya,xb,yb;
   float xi,yi,steps;
   printf("Enter the starting point");
   scanf("%d %d",&xa,&ya);
   printf("Enter the ending point");
   scanf("%d %d",&xb,&yb);
   initgraph(&gd,&gm,NULL);
   
   int dx = xb-xa;
   int dy = yb-ya;
   if(dy<dx)
       {
           steps=dx;
       }
   else
   {
       steps=dy;
   }
   xi=(float)dx/steps;
   yi=(float)dy/steps;
   float x=xa,y=ya;
   int k=0;
   while(k<steps){
       x+=xi;y+=yi;
       putpixel(x,y,WHITE);
       k++;
   }
   delay(5000);
   closegraph();
   return 0;
}
