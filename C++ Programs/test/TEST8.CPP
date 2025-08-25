#include<iostream>

int count(int x,int y)
{
 int a=0;
 while(x%y!=0)
 {
  x=x%y;
  a++;
  if(a>4)
   break;
  x=x*10;
 }
 return a;
}
int main()
{
 int x,i;
 double sum=0,z,p=1;
 clrscr();
 cout<<"\nEnter the value of x : ";
 cin>>x;
 i=1;
 while(1)
 {
  p=p*x;
  if(count(1,p)>4)
  {
   break;
  }
  z=1/p;
  sum=sum+z;
  i++;
 }
 cout<<"\nsum = "<<sum;
 return 0;
}