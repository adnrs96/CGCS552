#include<stdio.h>
#include<graphics.h>

//Get coords location WRT to viewport

int getLocationIdea(float viewport_minx,float viewport_miny,float viewport_maxx,float viewport_maxy,float x,float y)
{
  int location=0;
  if(x<viewport_minx)
  location |= 1;
  else if(x>viewport_maxx)
  location |= 2;
  if(y<viewport_miny)
  location |= 4;
  else if(y>viewport_maxy)
  location |= 8;
  return location;
}
int main()
{
  int gd = DETECT,gm;
  float xa,ya,xb,yb,xao,yao,xbo,ybo;
  float xatp,yatp,xbtp,ybtp;
  float viewport_minx,viewport_miny,viewport_maxx,viewport_maxy;
  printf("Enter the lower end diagnol coords of viewport\n");
  scanf("%f %f",&viewport_minx,&viewport_miny);
  printf("Enter the upper end diagnol coords of viewport\n");
  scanf("%f %f",&viewport_maxx,&viewport_maxy);
  printf("Enter the Line coords to plot\n");
  printf("Enter the starting point");
  scanf("%f %f",&xa,&ya);
  printf("Enter the ending point");
  scanf("%f %f",&xb,&yb);
  xatp=xa,xbtp=xb,yatp=ya,ybtp=yb;
  xao=xa,ybo=yb,yao=ya,xbo=xb;
  int locp1 = getLocationIdea(viewport_minx,viewport_miny,viewport_maxx,viewport_maxy,xa,ya);
  int locp2 = getLocationIdea(viewport_minx,viewport_miny,viewport_maxx,viewport_maxy,xb,yb);
  printf("%d %d \n",locp1,locp2 );
  if((locp1==0) && (locp2==0))
  {
    xatp=xa,xbtp=xb,yatp=ya,ybtp=yb;
  }
  else if((locp1&locp2) == 0 )
  {
    while((locp1&4) !=0)
    {
      xatp = xa + (((xb-xa)*(viewport_miny-ya))/(yb-ya));
      yatp = viewport_miny;
      xa=xatp;
      ya=yatp;
      locp1=getLocationIdea(viewport_minx,viewport_miny,viewport_maxx,viewport_maxy,xa,ya);
    }
    while((locp1&8) != 0)
    {
      xatp = xa + (((xb-xa)*(viewport_maxy-ya))/(yb-ya));
      yatp = viewport_maxy;
      xa=xatp;
      ya=yatp;
      locp1=getLocationIdea(viewport_minx,viewport_miny,viewport_maxx,viewport_maxy,xa,ya);
    }
    while((locp1&1) != 0)
    {
      xatp = viewport_minx;
      yatp = ya + (((yb-ya)*(viewport_minx-xa))/(xb-xa));
      xa=xatp;
      ya=yatp;
      locp1=getLocationIdea(viewport_minx,viewport_miny,viewport_maxx,viewport_maxy,xa,ya);
    }
    while((locp1&2) != 0)
    {
      xatp = viewport_maxx;
      yatp = ya + (((yb-ya)*(viewport_maxx-xa))/(xb-xa));
      xa=xatp;
      ya=yatp;
      locp1=getLocationIdea(viewport_minx,viewport_miny,viewport_maxx,viewport_maxy,xa,ya);
    }


    while((locp2&4) !=0)
    {
      xbtp = xa + (((xb-xa)*(viewport_miny-ya))/(yb-ya));
      ybtp = viewport_miny;
      xb=xbtp;
      yb=ybtp;
      locp2=getLocationIdea(viewport_minx,viewport_miny,viewport_maxx,viewport_maxy,xb,yb);
    }
    while((locp2&8) != 0)
    {
      xbtp = xa + (((xb-xa)*(viewport_maxy-ya))/(yb-ya));
      ybtp = viewport_maxy;
      xb=xbtp;
      yb=ybtp;
      locp2=getLocationIdea(viewport_minx,viewport_miny,viewport_maxx,viewport_maxy,xb,yb);
    }
   while((locp2&1) != 0)
    {
      xbtp = viewport_minx;
      ybtp = ya + (((yb-ya)*(viewport_minx-xa))/(xb-xa));
      xb=xbtp;
      yb=ybtp;
      locp2=getLocationIdea(viewport_minx,viewport_miny,viewport_maxx,viewport_maxy,xb,yb);
    }
    while((locp2&2) != 0)
    {
      xbtp = viewport_maxx;
      ybtp = ya + (((yb-ya)*(viewport_maxx-xa))/(xb-xa));
      xb=xbtp;
      yb=ybtp;
      locp2=getLocationIdea(viewport_minx,viewport_miny,viewport_maxx,viewport_maxy,xb,yb);
    }

  }
  else
  {
    xatp=0,xbtp=0,yatp=0,ybtp=0;
  }
  printf("%f %f %f %f\n",xatp,xbtp,yatp,ybtp);
  initgraph(&gd,&gm,NULL);
  //Draw viewport
  line(viewport_minx,viewport_miny,viewport_maxx,viewport_miny);
  line(viewport_minx,viewport_miny,viewport_minx,viewport_maxy);
  line(viewport_minx,viewport_maxy,viewport_maxx,viewport_maxy);
  line(viewport_maxx,viewport_miny,viewport_maxx,viewport_maxy);
  line(xatp,yatp,xbtp,ybtp);
  setlinestyle(DASHED_LINE,0,THICK_WIDTH);
  line(xao,yao,xbo,ybo);
  delay(5000);
  return 0;
}
