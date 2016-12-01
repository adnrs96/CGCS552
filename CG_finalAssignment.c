#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define PI 3.14159265
#define episilon 0.000001

typedef struct point{
  float x;
  float y;
} point,scale,translate;
typedef struct line{
  point p1;
  point p2;
} line;
typedef struct invariant2DTransformationpairs{
  int translation_translation;
  int rotation_rotation;
  int scaling_scaling;
  int translation_rotation;
  int translation_scaling;
  int rotation_scaling;
} inv2DTP;
void show_Menu()
{
  printf("2D Transformations Commutative pair detector and tester \n");
  printf("1) I wanna enter a line segment with all details for testing\n");
  printf("2) I will give details and want all lines starting with given start point tested\n");
  printf("3) I will give Transformations Details only, wanna see some lines being tested\n");
  printf("4) I want to just see cases being generated and tested\n");
  printf("5) I would prefer some uniform scaling in cases generated in 4th option\n");
  printf("6) Get me out of this weird screen\n");
}
void print_LineOperationsStatus(line l,translate t,translate t1,point r,float angle,float angle1,point sr,scale s,scale s1,inv2DTP statusCodes)
{
  for(int i=0;i<80;i++)
  printf("+");
  printf("\n");
  printf("Line Segment is from point P1(%d,%d) to P2(%d,%d)\n",(int)l.p1.x,(int)l.p1.y,(int)l.p2.x,(int)l.p2.y);
  printf("Translations Factors are T1(%f,%f) and T2(%f,%f)\n",t.x,t.y,t1.x,t1.y);
  printf("Pivot Point Is at (%f,%f) and angle of rotation are theta=%f , fyi=%f \n",r.x,r.y,angle,angle1);
  printf("Scaling point is at (%f,%f) and scaling factors are S1(%f,%f),S2(%f,%f)\n",sr.x,sr.y,s.x,s.y,s1.x,s1.y);
  printf("STATUS of 2D Transformation Invariance are :\n");
  printf("Translation(T1) Translation(T2) Pair :%s\n",statusCodes.translation_translation?"Commutative":"Non-Commutative");
  printf("Rotation(Theta) Rotation(fyi) Pair :%s\n",statusCodes.rotation_rotation?"Commutative":"Non-Commutative");
  printf("Scaling(S1) Scaling(S2) Pair :%s\n",statusCodes.scaling_scaling?"Commutative":"Non-Commutative");
  printf("Translation(T1) Rotation(Theta) Pair :%s\n",statusCodes.translation_rotation?"Commutative":"Non-Commutative");
  printf("Translation(T1) Scaling(S1) Pair :%s\n",statusCodes.translation_scaling?"Commutative":"Non-Commutative");
  printf("Rotation(Theta) Scaling(S1) Pair :%s\n",statusCodes.rotation_scaling?"Commutative":"Non-Commutative");
  for(int i=0;i<80;i++)
  printf("+");
  printf("\n");
  for(int i=0;i<80;i++)
  printf("|");
  printf("\n");
}
int check_Equality_Point(point p1,point p2)
{
  if((abs(p1.x-p2.x)<=episilon) && (abs(p1.y-p2.y)<=episilon))
  return 1;
  return 0;
}
int check_Equality_Line(line l1,line l2)
{
  if(check_Equality_Point(l1.p1,l2.p1) && check_Equality_Point(l1.p2,l2.p2))
  return 1;
  return 0;
}
//Converts a angle from degrees to radians
double to_Radian(float angle)
{
  return angle*(PI / 180.0);
}
/*Rotates a point about the given point of rotation and returns the resulting point
as a point structure
It recieves angle in degrees
*/
point rotate_Point_About_Point(point p, point r, float angle)
{
  point np;
  p.x -= r.x;
  p.y -= r.y;
  double ang = to_Radian(angle);
  np.x = (p.x * cos(ang)) - (p.y * sin(ang));
  np.y = (p.x * sin(ang)) + (p.y * cos(ang));
  np.x += r.x;
  np.y += r.y;
  return np;
}
/*Translates a given point using the translation factors supplied */
point translate_Point_WRT_Translation_Factors(point p,translate t)
{
  p.x += t.x;
  p.y += t.y;
  return p;
}
/*Scales a point using the scaling factors supplied w.r.t. a given point */
point scale_Point_WRT_Point(point p,point r,scale s)
{
  p.x -= r.x;
  p.y -= r.y;
  p.x *= s.x;
  p.y *= s.y;
  p.x += r.x;
  p.y += r.y;
  return p;
}
//Rotates a line segment about a point with a specific angle
line rotate_Line_About_Point(line l,point r,float angle)
{
  l.p1 = rotate_Point_About_Point(l.p1,r,angle);
  l.p2 = rotate_Point_About_Point(l.p2,r,angle);
  return l;
}
//Translates a line segment with effect of translation factors provided
line translate_Line_WRT_Translation_Factor(line l,translate t)
{
  l.p1 = translate_Point_WRT_Translation_Factors(l.p1,t);
  l.p2 = translate_Point_WRT_Translation_Factors(l.p2,t);
  return l;
}
//Scales a line segment using scaling factors w.r.t. a given point of view
line scale_Line_WRT_Point(line l,point r,scale s)
{
  l.p1 = scale_Point_WRT_Point(l.p1,r,s);
  l.p2 = scale_Point_WRT_Point(l.p2,r,s);
  return l;
}
inv2DTP try_2DTransformation_pairs(line l,translate t,translate t1,point r,float angle,float angle1,point sr,scale s,scale s1)
{
  inv2DTP _2dtp;
  line nl1,nl2;
  //Checking Translation and Translation pair
  nl1 = translate_Line_WRT_Translation_Factor(l,t);
  nl1 = translate_Line_WRT_Translation_Factor(nl1,t1);
  nl2 = translate_Line_WRT_Translation_Factor(l,t1);
  nl2 = translate_Line_WRT_Translation_Factor(nl2,t);
  _2dtp.translation_translation = check_Equality_Line(nl1,nl2);
  //Checking Rotation and Rotation pair
  nl1 = rotate_Line_About_Point(l,r,angle);
  nl1 = rotate_Line_About_Point(nl1,r,angle1);
  nl2 = rotate_Line_About_Point(l,r,angle1);
  nl2 = rotate_Line_About_Point(nl2,r,angle);
  _2dtp.rotation_rotation = check_Equality_Line(nl1,nl2);
  //Checking Scaling and Scaling pair
  nl1 = scale_Line_WRT_Point(l,sr,s);
  nl1 = scale_Line_WRT_Point(nl1,sr,s1);
  nl2 = scale_Line_WRT_Point(l,sr,s1);
  nl2 = scale_Line_WRT_Point(nl2,sr,s);
  _2dtp.scaling_scaling = check_Equality_Line(nl1,nl2);
  // Checking Translation and rotation pair
  nl1 = translate_Line_WRT_Translation_Factor(l,t);
  nl1 = rotate_Line_About_Point(nl1,r,angle);
  nl2 = rotate_Line_About_Point(l,r,angle);
  nl2 = translate_Line_WRT_Translation_Factor(nl2,t);
  _2dtp.translation_rotation = check_Equality_Line(nl1,nl2);
  // Checking Translation and Scaling pair
  nl1 = translate_Line_WRT_Translation_Factor(l,t);
  nl1 = scale_Line_WRT_Point(nl1,sr,s);
  nl2 = scale_Line_WRT_Point(l,sr,s);
  nl2 = translate_Line_WRT_Translation_Factor(nl2,t);
  _2dtp.translation_scaling = check_Equality_Line(nl1,nl2);
  // Checking Rotation and Scaling pair
  nl1 = rotate_Line_About_Point(l,r,angle);
  nl1 = scale_Line_WRT_Point(nl1,sr,s);
  nl2 = scale_Line_WRT_Point(l,sr,s);
  nl2 = rotate_Line_About_Point(nl2,r,angle);
  _2dtp.rotation_scaling = check_Equality_Line(nl1,nl2);

  return _2dtp;
}
void stressTesterEndPoint(point starting,translate t,translate t1,point r,float angle,float angle1,point sr,scale s,scale s1)
{
  line l;
  l.p1 = starting;
  srand((unsigned)time(NULL));
  int limit = rand()%500;
  for(int i=0;i<=limit;i+=(rand()%100))
  {
    for(int j=0;j<=limit;j+=(rand()%100))
    {
      l.p2.x = i;
      l.p2.y = j;
      inv2DTP temp = try_2DTransformation_pairs(l,t,t1,r,angle,angle1,sr,s,s1);
      print_LineOperationsStatus(l,t,t1,r,angle,angle1,sr,s,s1,temp);
    }
  }
}
void stressTesterStartPoint(translate t,translate t1,point r,float angle,float angle1,point sr,scale s,scale s1)
{
  point p;
  srand((unsigned)time(NULL));
  int limit = rand()%500;
  for(int i=0;i<=limit;i+=(rand()%100))
  {
    for(int j=0;j<=limit;j+=(rand()%100))
    {
      p.x = i;
      p.y = j;
      stressTesterEndPoint(p,t,t1,r,angle,angle1,sr,s,s1);
    }
  }
}
void stressTesterUformScalRotScalPointAtOrigin(translate t,translate t1,point p,float angle,float angle1,point sr,scale s,scale s1)
{
  if(s.x != s.y)
  {
    printf("Scaling factors not uniform ...\nTaking %f to be the scaling factor\n",s.x );
    s.y = s.x;
  }
  if((p.x != sr.x) || (p.y != sr.y))
  {
    printf("Pivot for rotation and scaing not equal\nTaking (%f,%f) to be the Pivot\n",p.x,p.y );
  }
  stressTesterStartPoint(t,t1,p,angle,angle1,p,s,s1);
}
/* This is a CASE generator which will generate cases num in number and depending upon choice variable
   Choose a further case generator */
void stressTestCreater(int num,int choice)
{
  srand((unsigned)time(NULL));
  translate t,t1;
  point r,sr;
  float angle,angle1;
  scale s,s1;
  for(int i=0;i<num;i++)
  {
    t.x = rand()%500;
    t.y = rand()%500;
    t1.x = rand()%500;
    t1.y = rand()%500;
    angle = rand()%361;
    angle1 = rand()%361;
    s.x = rand()%100+1;
    s.y = rand()%100+1;
    s1.x = rand()%100+1;
    s1.y = rand()%100+1;
    r.x = rand()%200;
    r.y = rand()%200;
    sr.x = rand()%200;
    sr.y = rand()%200;
    if(choice == 1)
    {
      stressTesterStartPoint(t,t1,r,angle,angle1,sr,s,s1);
    }
    if(choice == 2)
    {
      stressTesterUformScalRotScalPointAtOrigin(t,t1,r,angle,angle1,sr,s,s1);
    }
  }
}
int main()
{
  int choice,threshold;
  line l;
  translate t,t1;
  point r,sr;
  float angle,angle1;
  scale s,s1;
  while(1)
  {
    show_Menu();
    scanf("%d",&choice);
    if(choice == 1)
    {
      printf("Enter the starting point P1 of line segment\n");
      scanf("%f %f",&l.p1.x,&l.p1.y);
      printf("Enter the ending point P2 of line segment\n");
      scanf("%f %f",&l.p2.x,&l.p2.y);
      printf("Enter Translation Factors T1\n");
      scanf("%f %f",&t.x,&t.y);
      printf("Enter Translation Factors T2\n");
      scanf("%f %f",&t1.x,&t1.y);
      printf("Enter coordinates for Pivot Point for Rotation \n");
      scanf("%f %f",&r.x,&r.y);
      printf("Enter angle of rotation Theta\n");
      scanf("%f",&angle);
      printf("Enter angle of rotation fyi\n");
      scanf("%f",&angle1);
      printf("Enter coordinates for point of scaling reference\n");
      scanf("%f %f",&sr.x,&sr.y);
      printf("Enter scaling factors S1(Sx,Sy)\n");
      scanf("%f %f",&s.x,&s.y);
      printf("Enter scaling factors S2(Sx,Sy)\n");
      scanf("%f %f",&s1.x,&s1.y);
      inv2DTP temp = try_2DTransformation_pairs(l,t,t1,r,angle,angle1,sr,s,s1);
      print_LineOperationsStatus(l,t,t1,r,angle,angle1,sr,s,s1,temp);
    }
    if(choice == 2)
    {
      printf("Enter the starting point P1 of line segment\n");
      scanf("%f %f",&l.p1.x,&l.p1.y);
      printf("Enter Translation Factors T1\n");
      scanf("%f %f",&t.x,&t.y);
      printf("Enter Translation Factors T2\n");
      scanf("%f %f",&t1.x,&t1.y);
      printf("Enter coordinates for Pivot Point for Rotation \n");
      scanf("%f %f",&r.x,&r.y);
      printf("Enter angle of rotation Theta\n");
      scanf("%f",&angle);
      printf("Enter angle of rotation fyi\n");
      scanf("%f",&angle1);
      printf("Enter coordinates for point of scaling reference\n");
      scanf("%f %f",&sr.x,&sr.y);
      printf("Enter scaling factors S1(Sx,Sy)\n");
      scanf("%f %f",&s.x,&s.y);
      printf("Enter scaling factors S2(Sx,Sy)\n");
      scanf("%f %f",&s1.x,&s1.y);
      stressTesterEndPoint(l.p1,t,t1,r,angle,angle1,sr,s,s1);
    }
    if(choice == 3)
    {
      printf("Enter Translation Factors T1\n");
      scanf("%f %f",&t.x,&t.y);
      printf("Enter Translation Factors T2\n");
      scanf("%f %f",&t1.x,&t1.y);
      printf("Enter coordinates for Pivot Point for Rotation \n");
      scanf("%f %f",&r.x,&r.y);
      printf("Enter angle of rotation Theta\n");
      scanf("%f",&angle);
      printf("Enter angle of rotation fyi\n");
      scanf("%f",&angle1);
      printf("Enter coordinates for point of scaling reference\n");
      scanf("%f %f",&sr.x,&sr.y);
      printf("Enter scaling factors S1(Sx,Sy)\n");
      scanf("%f %f",&s.x,&s.y);
      printf("Enter scaling factors S2(Sx,Sy)\n");
      scanf("%f %f",&s1.x,&s1.y);
      stressTesterStartPoint(t,t1,r,angle,angle1,sr,s,s1);
    }
    if(choice == 4)
    {
      printf("Give some Threshold on number of cases\n");
      scanf("%d",&threshold);
      stressTestCreater(threshold,1);
    }
    if(choice == 5)
    {
      printf("Give some Threshold on number of cases\n");
      scanf("%d",&threshold);
      stressTestCreater(threshold,2);
    }
    if(choice == 6)
    {
      printf("Bye\n");
      return 0;
    }
  }
}
