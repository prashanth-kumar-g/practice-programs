// program to make below series, print it and find sum of it
// 1^1 + 2^2 + 3^3 + .......... + (n-1)^(n-1) + n^n
#include<iostream>

#include<math.h>
int main()
{
 int l,i;
 long int p,sum=0;
 clrscr();
 cout<<"\nEnter the limit : ";
 cin>>l;
 cout<<"\n";
 for(i=1;i<=l;i++)
 {
  p=pow(i,i);
  cout<<" + "<<p;
  sum=sum+p;
 }
 cout<<" = "<<sum;
 return 0;
}