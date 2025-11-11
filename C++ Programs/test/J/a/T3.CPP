// program to print armstrong number upto a limit (different method)
#include<iostream>

int main()
{
 long int l,i,n,c=1,r,j,exp,sum;
 clrscr();
 cout<<"\nEnter the limit : ";
 cin>>l;
 cout<<"\n";
 for(i=1;i<=l;i++)
 {
  n=i;
  if(i==10 || i==100 || i==1000 || i==10000 || i==100000 || i==1000000)
  {
   c++;
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