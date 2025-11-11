// dynamically allocating structure and self referential structure
#include<iostream>

#include<stdlib.h>
int main()
{
 struct node
 {
  int n;
  struct node *l;
 }*p;
 clrscr();
 p=(struct node*)malloc(3*(sizeof(struct node)));

 (p+1)->n=35;
 (p+1)->l=NULL;

 (p+2)->n=36;
 (p+2)->l=NULL;

 (p+3)->n=37;
 (p+3)->l=NULL;

 (p+1)->l=(p+2);
 (p+2)->l=(p+3);
 (p+3)->l=(p+1);

 cout<<"\n(p+1)->n = "<<(p+1)->n;
 cout<<"\n(p+2)->n = "<<(p+2)->n;
 cout<<"\n(p+3)->n = "<<(p+3)->n;

 cout<<"\n\n(p+1)->l = "<<(p+1)->l;
 cout<<"\n(p+2)->l = "<<(p+2)->l;
 cout<<"\n(p+3)->l = "<<(p+3)->l;

 cout<<"\n\n(p+1)->l->n = "<<(p+1)->l->n;
 cout<<"\n(p+2)->l->n = "<<(p+2)->l->n;
 cout<<"\n(p+3)->l->n = "<<(p+3)->l->n;

 cout<<"\n\n(p+1)->l->l = "<<(p+1)->l->l;
 cout<<"\n(p+2)->l->l = "<<(p+2)->l->l;
 cout<<"\n(p+3)->l->l = "<<(p+3)->l->l;

 return 0;
}