//program to add two numbers inside class
#include<iostream>

class add
{
 private : int a,b,sum;
 public : void getdata()
	  {
	   cout<<"Enter two numbers : ";
	   cin>>a>>b;
	  }
	  void putdata()
	  {
	   sum=a+b;
	   cout<<"sum = "<<sum;
	  }
};
int main()
{
 add a;
 clrscr();
 a.getdata();
 a.putdata();
 return 0;
}