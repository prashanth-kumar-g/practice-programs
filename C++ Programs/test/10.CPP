// program to swap two numbers using call
// by reference(pointers and reference)
#include<iostream>

void swap(int *,int *);
int main()
{
 int a,b;
 clrscr();
 cout<<"\nEnter two numbers : ";
 cin>>a>>b;
 cout<<"\nBefore Swapping\n";
 cout<<" a = "<<a<<endl;
 cout<<" b = "<<b;
 swap(&a,&b);
 cout<<"\nAfter Swapping\n";
 cout<<" a = "<<a<<endl;
 cout<<" b = "<<b;
 return 0;
}
void swap(int *x, int *y)
{
 int temp;
 temp=*x;
 *x=*y;
 *y=temp;
}
