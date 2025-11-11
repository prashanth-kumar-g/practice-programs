// program to check whether a given number is prime or not
#include<iostream>

int main()
{
 long int n,i,flag=0;
 clrscr();
 cout<<"\nEnter the number : ";
 cin>>n;
 for(i=2;i<=n-1;i++)
 {
  if(n%i==0)
  {
   flag=1;
   break;
  }
 }
 if(flag==1)
 {
  cout<<"\n"<<n<<" is not a prime number";
 }
 else
 {
  cout<<"\n"<<n<<" is a prime number";
 }
 return 0;
}