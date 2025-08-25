//program to display complex numbers using unary operators
#include<iostream>

class complex
{
 private : int a,b;
 public : void getdata()
	  {
	   cout<<"\nEnter two numbers : ";
	   cin>>a>>b;
	  }
	  void operator++()
	  {
	   a=++a;
	   b=++b;
	  }
	  void operator--()
	  {
	   a=--a;
	   b=--b;
	  }
	  void showdata()
	  {
	   cout<<a<<" + "<<b<<"i"<<endl;
	  }
};
int main()
{
 complex obj;
 clrscr();
 obj.getdata();
 ++obj;
 cout<<"\nIncrement Complex Numbers"<<endl;
 obj.showdata();
 --obj;
 cout<<"Decrement Complex Numbers"<<endl;
 obj.showdata();
 return 0;
}
