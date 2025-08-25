// program to make below series, print it and find sum of it
// b^1 + (b+1)^2 + (b+2)^3 + .......... + (b+n-2)^(n-1) + (b+n-1)^n
#include<iostream>

#include<math.h>
int main()
{
 int bs,be,l,i,x;
 long int p,sum=0;
 clrscr();
 cout<<"\nEnter the start base : ";
 cin>>bs;
 cout<<"Enter the end base : ";
 cin>>be;
 x=1;
 cout<<"\n";
 for(i=bs;i<=be;i++)
 {
  p=pow(i,x);
  cout<<" + "<<p;
  sum=sum+p;
  x=x+1;
 }
 cout<<" = "<<sum;
 return 0;
}