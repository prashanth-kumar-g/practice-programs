// dynamically allocating structure and self
// referential structure(input using user)
#include<iostream>

#include<stdlib.h>
int main()
{
 struct node
 {
  int n;
  struct node *l;
 }*p;
 int n;
 clrscr();

 cout<<"\nEnter the size : ";
 cin>>n;

 p=(struct node*)malloc(n*(sizeof(struct node)));

 (p+1)->l=NULL;
 cout<<"\nEnter "<<n<<" numbers\n\n";
 for(int i=1;i<=n;i++)
 {
  cout<<" "<<i<<")  ";
  cin>>(p+i)->n;
  (p+i)->l=(p+i+1);
 }
 (p+n)->l=(p+1);

 cout<<"\n\nThe elements are\n\n";
 for(i=1;i<=n;i++)
 {
  cout<<"(p+"<<i<<")->n = "<<(p+i)->n<<"   ";
 }

 cout<<"\n\n";
 for(i=1;i<=n;i++)
 {
  cout<<"(p+"<<i<<")->l = "<<(p+i)->l<<"   ";
 }

 cout<<"\n\n";
 for(i=1;i<=n;i++)
 {
  cout<<"(p+"<<i<<")->l->n = "<<(p+i)->l->n<<"   ";
 }

 cout<<"\n\n";
 for(i=1;i<=n;i++)
 {
  cout<<"(p+"<<i<<")->l->l = "<<(p+i)->l->l<<"   ";
 }

 free(p);

 return 0;
}