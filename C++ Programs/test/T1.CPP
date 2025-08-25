// program to check whether a number is armstrong or not
#include<iostream>

int main()
{
 long int n,m,p,c=0,r,i,exp,sum=0;
 clrscr();
 cout<<"\nEnter the number : ";
 cin>>n;
 m=n;
 while(n!=0)
 {
  c++;
  n=n/10;
 }
 p=m;
 while(m!=0)
 {
  r=m%10;
  exp=1;
  for(i=1;i<=c;i++)
  {
   exp=exp*r;
  }
  sum=sum+exp;
  m=m/10;
 }
 if(p==sum)
 {
  cout<<"\n"<<sum<<" is a armstrong number";
 }
 else
 {
  cout<<"\n"<<p<<" is not a armstrong number";
 }
 return 0;
}