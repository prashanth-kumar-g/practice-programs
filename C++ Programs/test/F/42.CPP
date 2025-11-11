// array inside a structure and a pointer variable to a structure
#include<iostream>

int main()
{
 struct node
 {
  int n;
  int a[3];
 }*p;
 clrscr();

 p->n=35;
 p->a[0]=10;
 p->a[1]=11;
 p->a[2]=12;

 cout<<"\n p->n = "<<p->n;
 cout<<"\n p->a[0] = "<<p->a[0];
 cout<<"\n p->a[1] = "<<p->a[1];
 cout<<"\n p->a[2] = "<<p->a[2];

 return 0;
}