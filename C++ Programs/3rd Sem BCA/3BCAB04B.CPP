//program to illustrate paramaeterised constructor
#include<iostream>

class sample
{
 public : int a,b;
	  sample(int x,int y)
	  {
	   a=x;
	   b=y;
	  }
	  int add()
	  {
	   return(a+b);
	  }
};
int main()
{
 sample s(10,20);
 clrscr();
 cout<<"\nsum = "<<s.add();
 return 0;
}