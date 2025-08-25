//program to illustrate constructor overloading
#include<iostream>

class sample
{
 public : int a;
	  sample()
	  {
	   a=10;
	  }
	  sample(int x)
	  {
	   a=x;
	  }
	  int display()
	  {
	   return a;
	  }
};
int main()
{
 sample s1,s2(20);
 clrscr();
 cout<<"\na = "<<s1.display();
 cout<<"\nb = "<<s2.display();
 return 0;
}