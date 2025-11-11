// program to print armstrong number between a given range
#include<iostream>

int main()
{
 long int a,b,i,n,c,r,j,exp,sum;
 clrscr();
 cout<<"\nEnter the first interval : ";
 cin>>a;
 cout<<"\nEnter the last interval : ";
 cin>>b;
 cout<<"\n";
 for(i=a;i<=b;i++)
 {
  c=0;
  n=i;
  while(n!=0)
  {
   c++;
   n=n/10;
  }
  n=i;
  sum=0;
  while(n!=0)
  {
   r=n%10;
   exp=1;
   for(j=1;j<=c;j++)
   {
    exp=exp*r;
   }
   sum=sum+exp;
   n=n/10;
  }
  n=i;
  if(n==sum)
  {
   cout<<"  "<<sum;
  }
 }
 return 0;
}