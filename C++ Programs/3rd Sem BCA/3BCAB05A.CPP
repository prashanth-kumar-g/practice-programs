//program to illustrate copy constructor
#include<iostream>

class sample
{
 public : int a;
	  sample(int x)
	  {
	   a=x;
	  }
	  sample(sample &obj)
	  {
	   a=obj.a;
	  }
	  int display()
	  {
	   return a;
	  }
};
int main()
{
 sample s1(10);
 clrscr();
 cout<<"\na = "<<s1.display()<<endl;
 sample s2=s1;
 cout<<"b = "<<s2.display();
 return 0;
}