// accessing structure members using pointer variable
// and self referential structure
#include<iostream>

int main()
{
 struct node
 {
  int n;
  struct node *l;
 }*s,p;
 clrscr();
 s->n=35;
 p.n=36;
 s->l=&p;
 p.l=s;
 cout<<"\ns->n = "<<s->n;
 cout<<"\ns->l = "<<s->l;
 cout<<"\n\np.n = "<<p.n;
 cout<<"\np.l = "<<p.l;
 cout<<"\n\ns->l->n = "<<s->l->l;
 cout<<"\np.l->n = "<<p.l->n;
 s=&p;
 cout<<"\n\ns = &p = "<<s;
 cout<<"\n\nvalues changed for s after s = &p";
 cout<<"\ns->n = "<<s->n;
 cout<<"\ns->l = "<<s->l;
 return 0;
}
