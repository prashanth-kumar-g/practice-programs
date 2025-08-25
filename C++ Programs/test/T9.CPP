// program to print prime numbers between a range
#include<iostream>

int main()
{
 long int a,b,i,j,flag;
 clrscr();
 cout<<"\nEnter the first interval : ";
 cin>>a;
 cout<<"\nEnter the last interval : ";
 cin>>b;
 cout<<"\n";
 for(i=a;i<=b;i++)
 {
  flag=0;
  for(j=2;j*j<=i;j++)
  {
   if(i%j==0)
   {
    flag=1;
    break;
   }
  }
  if(flag==0)
  {
   cout<<" "<<i;
  }
 }
 return 0;

}












