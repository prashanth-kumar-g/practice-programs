// dynamically allocating structure(input using user)
#include<iostream>

#include<stdlib.h>
int main()
{
 struct node
 {
  int n;
  char ch;
 }*p;
 int n;
 clrscr();
 cout<<"\nEnter the size : ";
 cin>>n;
 p=(struct node*)malloc(n*(sizeof(struct node)));

 cout<<"\nEnter four numbers and characters\n\n";
 for(int i=1;i<=n;i++)
 {
  cout<<" "<<i<<")  ";
  cin>>(p+i)->n>>(p+i)->ch;
 }

 cout<<"\n\nThe elements are\n";
 for(i=1;i<=n;i++)
 {
  cout<<"\n (p+"<<i<<")->n = "<<(p+i)->n;
  cout<<"   "<<"(p+"<<i<<")->ch = "<<(p+i)->ch;
 }

 free(p);

 return 0;
}