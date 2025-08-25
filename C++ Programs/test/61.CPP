// recursion function
#include<iostream>

int fib(int n)
{
 if(n==0)
 {
  return 0;
 }
 else if(n==1)
 {
  return(1);
 }
 else
 {
  return( fib(n-2) + fib(n-1) );
 }
}
int main()
{
 int n;
 clrscr();
 cout<<"\nEnter the position : ";
 cin>>n;
 cout<<"\nThe term in fibonnaci sequence at position "<<n<<" is "<<fib(n);
 return 0;
}