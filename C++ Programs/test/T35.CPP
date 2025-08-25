// program to make below series, print it and find sum of it
// 1^x + 2^(x+1) + 3^(x+2) + .......... + (n-1)^(x+n-2) + n^(x+n-1)
#include<iostream>

#include<math.h>
int main()
{
 int xs,xe,l,i,b;
 long int p,sum=0;
 clrscr();
 cout<<"\nEnter the start exponent : ";
 cin>>xs;
 cout<<"Enter the end exponent : ";
 cin>>xe;
 b=xs;
 cout<<"\n";
 for(i=1;i<=xe-xs+1;i++)
 {
  p=pow(i,b);
  cout<<" + "<<p;
  sum=sum+p;
  b=b+1;
 }
 cout<<" = "<<sum;
 return 0;
}