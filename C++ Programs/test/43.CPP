// self referential pointer and array of structure
#include<iostream>

int main()
{
 struct node
 {
  int n;
  struct node *a;
 }x[3];
 clrscr();

 x[0].n=35;
 x[1].n=36;
 x[2].n=37;

 x[0].a=&x[1];
 x[1].a=&x[2];
 x[2].a=&x[0];

 cout<<"\n x[0] = "<<x[0].n;
 cout<<"\n x[1] = "<<x[1].n;
 cout<<"\n x[2] = "<<x[2].n;

 cout<<"\n\n x[0].a = "<<x[0].a;
 cout<<"\n x[1].a = "<<x[1].a;
 cout<<"\n x[2].1 = "<<x[2].a;

 cout<<"\n\n x[0].a->n = "<<x[0].a->n;
 cout<<"\n x[1].a->n = "<<x[1].a->n;
 cout<<"\n x[2].a->n = "<<x[2].a->n;

 return 0;
}