// program to input and print array elements
#include<iostream>

int main()
{
 int n,i,a[5];
 clrscr();
 cout<<"\nEnter the size : ";
 cin>>n;
 cout<<"Enter the elements : ";
 for(i=1;i<=n;i++)
 {
  cin>>a[i];
 }
 cout<<"The Elements are : ";
 for(i=1;i<=n;i++)
 {
  cout<<a[i]<<" ";
 }
 return 0;
}
