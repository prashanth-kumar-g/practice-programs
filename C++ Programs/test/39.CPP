// wild pointer
#include<iostream>

#include<stdlib.h>
int main()
{
 clrscr();
 int a=35;

 int *ptr;   // this is a wild pointer
 *ptr=36;    // wild ponter can't be dereferenced

 ptr=&a;     // this is no longer a wild pointer
 cout<<"\n *ptr = "<<*ptr;   // this can be dereferenced

 return 0;
}
