// program to make below series, print it and find sum of it
// 1^x + 2^x + 3^x + .......... + (n-1)^x + n^x
#include<iostream>

#include<math.h>
int main()
{
 int x,l,i;
 long int p,sum=0;
 clrscr();
 cout<<"\nEnter the exponent : ";
 cin>>x;
 cout<<"Enter the limit : ";
 cin>>l;
 cout<<"\n";
 for(i=1;i<=l;i++)
 {
  p=pow(i,x);
  cout<<" + "<<p;
  sum=sum+p;
 }
 cout<<" = "<<sum;
 return 0;
}