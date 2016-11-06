#include<graphics.h>
#include<stdio.h>
#include<math.h>
void ellipseDrawPoints(float x_center,float y_center,float x,float y)
{
  putpixel(x_center+x,y_center+y,WHITE);
  putpixel(x_center-x,y_center+y,WHITE);
  putpixel(x_center+x,y_center-y,WHITE);
  putpixel(x_center-x,y_center-y,WHITE);
}
int main()
{
   int gd = DETECT,gm;
   float xa,ya,ra,rb;

   printf("Enter the Center of Ellipse\n");
   scanf("%f %f",&xa,&ya);
   printf("Enter the x axis length of Ellipse ' a '\n");
   scanf("%f",&ra);
   printf("Enter the y axis length of Ellipse ' b '\n");
   scanf("%f",&rb);
   initgraph(&gd,&gm,NULL);
   float x = 0,y=rb;
   float px = 0,py = 2*ra*ra*y,p=rb*rb-(ra*ra*rb)+(0.25*ra*ra);
   ellipseDrawPoints(xa,ya,x,y);
   while(px<py)
   {
     x++;
     px+=2*rb*rb;
     if(p<0)
     {
       p+=rb*rb+px;
     }
     else
     {
        y--;
        py-=2*ra*ra;
        p+=rb*rb+px-py;
     }
     ellipseDrawPoints(xa,ya,x,y);
  }
  p=rb*rb*(x+0.5)*(x+0.5)+ra*ra*(y-1)*(y-1)-ra*ra*rb*rb;
  while(y>0)
  {
    y--;
    py-=2*ra*ra;
    if(p>0)
    {
      p+=ra*ra-py;
    }
    else
    {
       x++;
       px+=2*rb*rb;
       p+=ra*ra+px-py;
    }
    ellipseDrawPoints(xa,ya,x,y);
 }

   delay(5000);
   closegraph();
   return 0;
}
