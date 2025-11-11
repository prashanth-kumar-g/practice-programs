// program to make below series, print it and find sum of it
// b^1 + b^2 + b^3 + .......... + b^(n-1) + b^n
#include<iostream>

#include<math.h>
int main()
{
 int b,l,i;
 long int p,sum=0;
 clrscr();
 cout<<"\nEnter the base : ";
 cin>>b;
 cout<<"Enter the limit : ";
 cin>>l;
 cout<<"\n";
 for(i=1;i<=l;i++)
 {
  p=pow(b,i);
  cout<<" + "<<p;
  sum=sum+p;
 }
 cout<<" = "<<sum;
 return 0;
}