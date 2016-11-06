#include<graphics.h> 
int main()
{
   int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
   initgraph(&gd,&gm,NULL);
   line(10,10,100,10);
   line(10,10,10,100);
   line(10,100,100,100);
   line(100,10,100,100);
   
   delay(5000);
   closegraph();
   return 0;
}