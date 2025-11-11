// array inside a structure and array of structure
#include<iostream>

int main()
{
 struct node
 {
  int n;
  int a[3];
 }x[2];
 clrscr();

 x[0].n=35;
 x[1].n=36;

 x[0].a[0]=21;
 x[0].a[1]=22;
 x[0].a[2]=23;

 x[1].a[0]=24;
 x[1].a[1]=25;
 x[1].a[2]=26;

 cout<<"\n x[0].n = "<<x[0].n;
 cout<<"\n x[1].n = "<<x[1].n;

 cout<<"\n\n x[0].a[0] = "<<x[0].a[0];
 cout<<"\n x[0].a[1] = "<<x[0].a[1];
 cout<<"\n x[0].a[2] = "<<x[0].a[2];

 cout<<"\n\n x[1].a[0] = "<<x[1].a[0];
 cout<<"\n x[1].a[1] = "<<x[1].a[1];
 cout<<"\n x[1].a[2] = "<<x[1].a[2];

 return 0;
}