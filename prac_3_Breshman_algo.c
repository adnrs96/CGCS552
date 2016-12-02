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
   if((xb<xa && yb<ya)||(xb>xa && yb>ya))
   {
     if (xb<xa && yb<ya)
     {
       int temp=xb;
       xb=xa;
       xa=temp;
       temp=yb;
       yb=ya;
       ya=temp;
     }
     int dx = xb-xa;
     int dy = yb-ya;
     int D = dy-dx;
     int y = ya;
     for ( int x = xa;x<xb;x++)
     {
       putpixel(x,y,WHITE);
       if ( D>=0)
       {
         y++;
         D=D-dx;
       }
       D=D+dy;
     }
   }
   else
   {
     if (xb<xa && yb>ya)
     {
       int temp=xb;
       xb=xa;
       xa=temp;
       temp=yb;
       yb=ya;
       ya=temp;
     }
     int dx = xb-xa;
     int dy = ya-yb;
     int D = dy-dx;
     int x = xa;
     for ( int y = ya;y>yb;y--)
     {
       putpixel(x,y,WHITE);
       if ( D>=0)
       {
         x++;
         D=D-dy;
       }
       D=D+dx;
     }
   }
   delay(5000);
   closegraph();
   return 0;
}
