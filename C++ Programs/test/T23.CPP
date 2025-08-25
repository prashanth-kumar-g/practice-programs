// program to make a geometric series,
// print it and find the sum of it (last term)
#include<iostream>

int main()
{
 int a,r,n,i,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the common ratio : ";
 cin>>r;
 cout<<"Enter the last term : ";
 cin>>n;
 cout<<"\n";
 for(i=a;i<=n;i=i*r)
 {
  cout<<" + "<<i;
  sum=sum+i;
 }
 cout<<" = "<<sum;
 return 0;
}

