#include<stdio.h>
#include<graphics.h>
int main(){
  int gd=DETECT,gm;
  initgraph(&gd, &gm, "");
  int ox = getmaxx()/2,oy = getmaxy()/2;
  int dx[5] = {20, 60, 100, 140, 180}, dy[5] = {200, 150, 190, 50, 70};
  line(ox,oy,getmaxx(),oy);
  line(ox,oy,ox,0);

  for(int i=0; i < 4; i++){
    line(ox+dx[i], oy-dy[i], ox+dx[i+1], oy-dy[i+1]);
  }
  getch();
  closegraph();
}
