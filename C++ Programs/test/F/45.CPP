// self referential structure and dynamically
// allocated structure pointer variables
#include<iostream>

#include<stdlib.h>
int main()
{
 struct node
 {
  int n;
  struct node *l;
 };
 clrscr();

 struct node *a,*b,*c;

 a=(struct node *)malloc(sizeof(struct node));
 b=(struct node *)malloc(sizeof(struct node));
 c=(struct node *)malloc(sizeof(struct node));

 a->n=35;
 a->l=b;

 b->n=36;
 b->l=c;

 c->n=37;
 c->l=NULL;

 cout<<"\n a->n = "<<a->n;
 cout<<"\n b->n = "<<b->n;
 cout<<"\n c->n = "<<c->n;

 cout<<"\n\n a->l = "<<a->l;
 cout<<"\n b->l = "<<b->l;
 cout<<"\n c->l = "<<c->l;

 cout<<"\n\n a->l->n = "<<a->l->n;
 cout<<"\n b->l->n = "<<b->l->n;
 cout<<"\n c->l->n = "<<c->l->n;

 struct node *p;


 p=a;                     // address of pointer a is stored inside pointer p
			      // after p=a;
 cout<<"\n\n p->n = "<<p->n;  // p->n=a->n;
 cout<<"\n p->l = "<<p->l;    // and p->l=a->l; and previous step a->l=b;


 p=p->l;                  // address of pointer p->l is now currently stored inside pointer p, and in previous steps p->l=a->l; and before that a->l=b;, so therefore address pointer b is now stored in pointer p (p=b)
			      // after p=p->l=a->l=b;
 cout<<"\n\n p->n = "<<p->n;  // p->n=b->n;
 cout<<"\n p->l = "<<p->l;    // and p->l=b->l; and previous step b->l=c;


 p=p->l;                  // address of pointer p->l is now currently stored inside pointer p, and in previous steps p->l=b->l; and before that b->l=c;, so therefore address pointer c is now stored in pointer p (p=c)
			       // after p=p->l=b->l=c;
 cout<<"\n\n p->n = "<<p->n;   // p->n=c->n;
 cout<<"\n p->l = "<<p->l;     // and p->l=c->l; and previous step c->l=NULL;


 free(a);
 free(b);
 free(c);

 return 0;
}


