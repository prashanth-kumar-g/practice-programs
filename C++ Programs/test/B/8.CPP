// program to swap two numbers using call by value
#include<iostream>

void swap(int,int);
int main()
{
 int a,b;
 clrscr();
 cout<<"\nEnter two numbers : ";
 cin>>a>>b;
 cout<<"\nBefore Swapping\n";
 cout<<" a = "<<a<<endl;
 cout<<" b = "<<b;
 swap(a,b);
 return 0;
}
void swap(int x, int y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
 cout<<"\nAfter Swapping\n";
 cout<<" a = "<<x<<endl;
 cout<<" b = "<<y;
}
