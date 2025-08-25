//program to illustrate method overloading
#include<iostream>

class addition
{
 public : int add(int x,int y)
	  {
	   return(x+y);
	  }
	  int add(int x,int y,int z)
	  {
	   return(x+y+z);
	  }
};
int main()
{
 addition a1;
 int x,y,z;
 clrscr();
 cout<<"\nEnter three numbers : ";
 cin>>x>>y>>z;
 cout<<"\nsum of first two numbers = "<<a1.add(x,y);
 cout<<"\nsum of all three numbers = "<<a1.add(x,y,z);
 return 0;
}