// program to make below series, print it and find sum of it
// b^x + (b+1)^(x+1) + (b+2)^(x+2) + .......... + (b+n-1)^(x+n-1) + n^(x+n)
#include<iostream>

#include<math.h>

int main()
{
 int bs,be,xs,xe,l,i,x;
 long int p,sum=0;
 clrscr();
 cout<<"\nEnter the start base : ";
 cin>>bs;
 cout<<"Enter the end base : ";
 cin>>be;
 cout<<"Enter the start exponent : ";
 cin>>xs;
 x=xs;
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


/* OR  */

/*
int main()
{
 int bs,xs,xe,l,i,b;
 long int p,sum=0;
 clrscr();
 cout<<"\nEnter the start base : ";
 cin>>bs;
 cout<<"Enter the start exponent : ";
 cin>>xs;
 cout<<"Enter the end exponent : ";
 cin>>xe;
 b=bs;
 cout<<"\n";
 for(i=xs;i<=xe;i++)
 {
  p=pow(b,i);
  cout<<" + "<<p;
  sum=sum+p;
  b=b+1;
 }
 cout<<" = "<<sum;
 return 0;
}
*/