/*program to print half-pyramid star pattern*/
#include<stdio.h>

int main()
{
 int n,i,j;
 
 printf("\nEnter the number of lines : ");
 scanf("%d",&n);
 printf("\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=i;j++)
  {
   printf("* ");
  }
  printf("\n");
 }
 return 0;
}