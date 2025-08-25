#include<iostream>

#include"swap.h"
int main()
{
 clrscr();
 int a=10,b=20;
 cout<<"\nBefore Swapping"<<endl;
 cout<<" a = "<<a<<endl;
 cout<<" b = "<<b;
 swap(a,b);
 cout<<"\nAfter Swapping"<<endl;
 cout<<" a = "<<a<<endl;
 cout<<" b = "<<b;
 return 0;
}
