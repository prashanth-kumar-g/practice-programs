/*program to find the roots of a quadratic equation*/
#include<stdio.h>

#include<math.h>
int main()
{
 float a,b,c,d,r1,r2,real_part,imag_part;
 
 printf("\nEnter the co-efficients of the quadratic equation\n");
 scanf("%f %f %f",&a,&b,&c);
 d=(b*b-4*a*c);
 if(d>0)
 {
  printf("\nRoots are real and distinct");
  r1=(-b+sqrt(d))/(2*a);
  r2=(-b-sqrt(d))/(2*a);
  printf("\nroot1 = %f",r1);
  printf("\nroot2 = %f",r2);
 }
 else if(d==0)
 {
  printf("\nRoots are real and equal");
  r1=r2=(-b)/(2*a);
  printf("\nroot1 = %f",r1);
  printf("\nroot2 = %f",r2);
 }
 else
 {
  printf("\nRoots are imaginary");
  d=sqrt(abs(d));
  real_part=-b/(2*a);
  imag_part=d/(2*a);
  printf("\nroot1 = %f+%fi",real_part,imag_part);
  printf("\nroot2 = %f-%fi",real_part,imag_part);
 }
 return 0;
}
