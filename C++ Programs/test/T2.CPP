// program to print armstrong number upto a limit
#include<iostream>

int main()
{
 long int l,i,n,c,r,j,exp,sum;
 clrscr();
 cout<<"\nEnter the limit : ";
 cin>>l;
 cout<<"\n";
 for(i=0;i<=l;i++)
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