// null pointer
#include<iostream>

#include<stdlib.h>
int main()
{
 clrscr();
 int a=35;
 int *ptr=NULL;
 cout<<"\nfirst  *ptr = NULL";
 cout<<"\n ptr = "<<ptr;
 if(ptr!=NULL)
 {
  cout<<"\n *ptr = "<<*ptr;
 }
 else
 {
  cout<<"\n *ptr = undefined (NULL pointer can't be dereferenced)";
 }
 ptr=&a;
 cout<<"\n\nafter  *ptr = &a";
 cout<<"\n ptr = "<<ptr;
 cout<<"\n *ptr = "<<*ptr<<" (it can be dereferenced now)";
 return 0;
}
