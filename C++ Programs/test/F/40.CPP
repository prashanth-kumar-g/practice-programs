// array inside a structure
#include<iostream>

int main()
{
 struct node
 {
  int n;
  int a[3];
 }x;
 clrscr();
 x.n=35;
 x.a[1]=10;
 x.a[2]=11;
 x.a[3]=12;
 cout<<"\n x.n = "<<x.n;
 cout<<"\n x.a[1] = "<<x.a[1];
 cout<<"\n x.a[2] = "<<x.a[2];
 cout<<"\n x.a[3] = "<<x.a[3];
 return 0;
}