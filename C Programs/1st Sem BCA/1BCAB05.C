/*program to check whether the given 3-digit number is armstrong
number or not*/
#include<stdio.h>

int main()
{
 int n,r,s,n1;
 
 printf("\nEnter a number : ");
 scanf("%d",&n);
 n1=n;
 s=0;
 while(n!=0)
 {
  r=n%10;
  s=s+r*r*r;
  n=n/10;
 }
 if(n1==s)
  printf("%d is a armstrong number",s);
 else
  printf("%d is not a armstrong number",n1);
 return 0;
}