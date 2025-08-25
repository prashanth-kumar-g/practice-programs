//program to illustrate default constructor
#include<iostream>

class sample
{
 public : int a;
	  sample()
	  {
	   a=10;
	  }
	  void display()
	  {
	   cout<<"\na = "<<a<<endl;
	  }
};
int main()
{
 sample s;
 clrscr();
 s.display();
 return 0;
}