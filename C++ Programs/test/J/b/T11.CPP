// program to print and find sum of the first n natural numbers
#include<iostream>

int main()
{
 int n,i,sum=0;
 clrscr();
 cout<<"\nEnter the limit : ";
 cin>>n;
 cout<<"\n";
 for(i=1;i<=n;i++)
 {
  cout<<" + "<<i;
  sum=sum+i;
 }
 cout<<" = "<<sum;
 return 0;
}





