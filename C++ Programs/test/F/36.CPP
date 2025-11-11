// void pointer
#include<iostream>

int main()
{
 clrscr();
 int a=3;
 float b=3.14;
 void *ptr;
 ptr=&a;
 cout<<"\n a = "<<a;
 cout<<"\n &a = "<<&a;
 cout<<"\n ptr = "<<ptr;
 cout<<"\n *((int *)ptr) = "<<*((int *)ptr); // void pointer can't be dereferenced directly
 ptr=&b;                                     // so typecast it into required data type
 cout<<"\n\n b = "<<b;
 cout<<"\n &b = "<<&b;
 cout<<"\n ptr = "<<ptr;
 cout<<"\n *((float *)ptr) = "<<*((float *)ptr);
 return 0;
}