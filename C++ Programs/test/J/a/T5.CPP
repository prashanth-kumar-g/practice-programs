// program to check whether a number is
// armstrong or not (using mathematical function)
#include<iostream>

#include<math.h>
int main()
{
 long int n,m,c,r,sum=0;
 clrscr();
 cout<<"\nEnter the number : ";
 cin>>n;
 c=log10(n)+1;
 m=n;
 while(n!=0)
 {
  r=n%10;
  sum=sum+pow(r,c);
  n=n/10;
 }
 if(m==sum)
 {
  cout<<"\n"<<sum<<" is a armstrong number";
 }
 else
 {
  cout<<"\n"<<m<<" is not a armstrong number";
 }
 return 0;
}

