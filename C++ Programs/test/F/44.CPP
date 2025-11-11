// structure inside a structure
#include<iostream>

int main()
{
 struct node
 {
  int a;
  struct inode
  {
   int b;
  }p;
 }q;
 clrscr();

 q.a=35;
 q.p.b=36;

 cout<<"\n q.a = "<<q.a;
 cout<<"\n q.p.b = "<<q.p.b;

 return 0;
}