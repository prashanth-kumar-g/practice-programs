//program to illustarte virtual function
#include<iostream>

class base
{
 public : virtual void show()
	  {
	   cout<<"\nHello Base Class"<<endl;
	  }
};
class derived:public base
{
 public : void show()
	  {
	   cout<<"\nHello Derived Class"<<endl;
	  }
};
int main()
{
 clrscr();
 base bobj;
 derived dobj;
 base *bptr;
 bptr=&bobj;
 bptr->show();
 bptr=&dobj;
 bptr->show();
 return 0;
}