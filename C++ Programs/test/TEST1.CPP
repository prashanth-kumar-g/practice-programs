#include<iostream>

int main()
{
 int a[10],i,n,e[10],o[10];
 clrscr();

 cout<<"\nEnter the size of the array : ";
 cin>>n;
 cout<<"Enter the elements of the array : ";
 for(i=1;i<=n;i++)
 {
  cin>>a[i];
 }

 // dividing a array into two array of even and odd
 int c=1,d=1;
 for(i=1;i<=n;i++)
 {
  if(a[i]%2==0)
  {
   e[c]=a[i];
   c++;
  }
  else
  {
   o[d]=a[i];
   d++;
  }
 }

 cout<<"\nThe given array is  :  ";
 for(i=1;i<=n;i++)
 {
  cout<<a[i]<<"  ";
 }
 cout<<"\nThe first array is  :  ";
 for(i=1;i<c;i++)
 {
  cout<<e[i]<<"  ";
 }
 cout<<"\nThe second array is  :  ";
 for(i=1;i<d;i++)
 {
  cout<<o[i]<<"  ";
 }
 return 0;
}