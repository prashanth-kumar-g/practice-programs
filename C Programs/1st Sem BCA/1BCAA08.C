/*program to find the value of cos(x) using cos series*/
#include<stdio.h>

#define PI 3.14
int main()
{
 float teta,x,cos_sum,term;
 int n,i;
 
 printf("\nEnter the angle in degree\n");
 scanf("%f",&teta);
 printf("Enter the number of terms\n");
 scanf("%d",&n);
 x=teta*PI/180;
 cos_sum=1;
 term=1;
 for(i=1;i<=n;i++)
 {
  term=-term*x*x/((2*i)*(2*i-1));
  cos_sum=cos_sum+term;
 }
 printf("\ncos(%f) = %4.4f",teta,cos_sum);
 return 0;
}
