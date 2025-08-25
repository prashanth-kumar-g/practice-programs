/*program to generate a multiplicatio table*/
#include<stdio.h>

int main()
{
 int n,l,i;
 
 printf("\nEnter a number : ");
 scanf("%d",&n);
 printf("Enter the limit : ");
 scanf("%d",&l);
 for(i=1;i<=l;i++)
 {
  printf("\n%d * %d = %d",n,i,n*i);
 }
 return 0;
}