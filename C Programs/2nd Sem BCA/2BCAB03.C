/*program to find factorial of a number using recursion*/
#include<stdio.h>

#include<stdlib.h>
long int fact(int);
int main()
{
 int n;
 long int f;
 
 printf("\nEnter a number : ");
 scanf("%d",&n);
 if(n<0)
 {
  printf("it is a negative number ");
  exit(0);
 }
 f=fact(n);
 printf("%d ! = %ld",n,f);
 return 0;
}
long int fact(int x)
{
 if(x==0)
  return 1;
 else
  return(x*fact(x-1));
}











