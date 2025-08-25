// program to print prime numbers upto a limit
#include<iostream>

int main()
{
 long int l,i,j,flag;
 clrscr();
 cout<<"\nEnter the limit : ";
 cin>>l;
 cout<<"\n";
 for(i=2;i<=l;i++)
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