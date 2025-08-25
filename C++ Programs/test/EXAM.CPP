#include<iostream>

class outside
{
 public : void show()
	  {
	   cout<<<"\n Hello Outside Class";
	  }
	  class inside
	  {
	   public : void show()
		    {
		     cout<<"\n Hello Inside Class";
		    }
	  };
};
int main()
{
 clrscr();
 outside o;
 outside::inside i;
 o.show();
 i.show();
 return 0;