#include <stdio.h>
#include <math.h>

float f(float x,float y,float z)
{
  return ((12.6-2*y+2*z)/26);
  
}

float s(float x,float y,float z)
{
  return ((-14.3+z-3*x)/27);
 
}

float t(float x,float y,float z)
{
  return ((6-2*x+3*y)/17);
 
}

void main()
{
  float x0,y0,z0,x1=0,y1=0,z1=0,tempx,tempy,tempz,acc=0.0005;
  int iteration=0;
  printf("Enter initial guesses:\n");
  scanf("%f%f%f",&x0,&y0,&z0);
    printf("  Value of      :  x1       y1       z1\n");
  do
  {
    tempx=x1;
    tempy=y1;
    tempz=z1;

    x1=f(x0,y0,z0);
    y1=s(x0,y0,z0);
    z1=t(x0,y0,z0);
    printf("In %dth iteration : %lf %lf %lf\n",iteration,x1,y1,z1);
    iteration++;
    
    x0=x1;
    y0=y1;
    z0=z1;
  }while(fabs(tempx-x1)>acc && fabs(tempy-y1)>acc && fabs(tempz-z1)>acc);

   printf("X1 : %lf\n",x1);
   printf("Y1 : %lf\n",y1);
   printf("Z1 : %lf\n",z1);
}
