#include<iostream>

int fact(int n)
{
 if(n<0)
  return -1;
 else if(n==0 || n==1)
  return 1;
 else
  return n*fact(n-1);
}
int main()
{
 int n,i,r,f,nPr,nCr;
 clrscr();
 cout<<"\nEnter the value of n : ";
 cin>>n;
 cout<<"Enter the value of r : ";
 cin>>r;
 nPr=fact(n)/(fact(n-r));
 nCr=nPr/fact(r);
 cout<<"\n"<<n<<"P"<<r<<" = "<<nPr;
 cout<<"\n"<<n<<"C"<<r<<" = "<<nCr;
 return 0;
}