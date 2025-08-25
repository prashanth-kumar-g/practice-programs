// program to make a arithmetic series,
// print it and find the sum of it (last term)
#include<iostream>

int main()
{
 int a,d,n,i,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the common difference : ";
 cin>>d;
 cout<<"Enter the last term : ";
 cin>>n;
 cout<<"\n";
 for(i=a;i<=n;i=i+d)
 {
  cout<<" + "<<i;
  sum=sum+i;
 }
 cout<<" = "<<sum;
 return 0;
}