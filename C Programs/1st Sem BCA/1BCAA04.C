/*program to display fibonacci series using recursion function*/
#include<stdio.h>

int fibo(int);
int main()
{
 int n,i=0;
 
 printf("\nEnter the number of terms : ");
 scanf("%d",&n);
 while(i<n)
 {
  ++i;
  printf("%d ",fibo(i));
 }
 return 0;
}
int fibo(int n)
{
 if(n==0 || n==1)
  return(0);
 else if(n==2)
  return(1);
 else
  return(fibo(n-1)+fibo(n-2));
  return 0;
}