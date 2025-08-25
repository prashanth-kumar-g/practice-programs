//program to add two numbers outside class
#include<iostream>

class add
{
 private : int a,b,sum;
 public : void getdata();
	  void putdata();
};
void add::getdata()
{
 cout<<"Enter two numbers : ";
 cin>>a>>b;
}
void add::putdata()
{
 sum=a+b;
 cout<<"sum = "<<sum;
}
int main()
{
 add a;
 clrscr();
 a.getdata();
 a.putdata();
 return 0;
}