// dynamically allocating structure
#include<iostream>

#include<stdlib.h>
int main()
{
 struct node
 {
  int n;
  char ch;
 }*p;
 clrscr();
 p=(struct node*)malloc(3*(sizeof(struct node)));

 p->n=35;
 p->ch='A';
 (p+1)->n=36;
 (p+1)->ch='B';
 (p+2)->n=37;
 (p+2)->ch='C';

 cout<<"\np->n = "<<p->n;
 cout<<"\np->ch = "<<p->ch;
 cout<<"\np->n = "<<(p+1)->n;
 cout<<"\np->ch = "<<(p+1)->ch;
 cout<<"\np->n = "<<(p+2)->n;
 cout<<"\np->ch = "<<(p+2)->ch;

 free(p);

 return 0;
}