// accessing structure members using variable
// and self referential structure
#include<iostream>

int main()
{
 struct node
 {
  int n;
  char ch;
  struct node *l;
 };
 clrscr();

 struct node var1;
 var1.n=35;
 var1.ch='A';
 var1.l=NULL;

 struct node var2;
 var2.n=36;
 var2.ch='B';
 var2.l=NULL;

 struct node var3;
 var3.n=37;
 var3.ch='C';
 var3.l=NULL;

 var1.l=&var2;
 var2.l=&var3;
 var3.l=&var1;

 cout<<"\nvar1.n = "<<var1.n;
 cout<<"\nvar2.n = "<<var2.n;
 cout<<"\nvar3.n = "<<var3.n;

 cout<<"\n\nvar1.ch = "<<var1.ch;
 cout<<"\nvar2.ch = "<<var2.ch;
 cout<<"\nvar3.ch = "<<var3.ch;

 cout<<"\n\nvar1.l = "<<var1.l;
 cout<<"\nvar2.l = "<<var2.l;
 cout<<"\nvar3.l = "<<var3.l;

 cout<<"\n\nvar1.l->n = "<<var1.l->n;
 cout<<"\nvar2.l->n = "<<var2.l->n;
 cout<<"\nvar3.l->n = "<<var3.l->n;

 cout<<"\n\nvar1.l->ch = "<<var1.l->ch;
 cout<<"\nvar2.l->ch = "<<var2.l->ch;
 cout<<"\nvar3.l->ch = "<<var3.l->ch;

 return 0;
}
