//program to show returning current object, accessing member data of
//current object and returning values of objects using this pointer
#include<iostream>

class rectangle
{
 private : int length,width;
 public : void setlength(int len)
	  {
	   this->length=len;
	  }
	  int getlength()
	  {
	   return(this->length);
	  }
	  void setwidth(int wth)
	  {
	   width=wth;
	  }
	  int getwidth()
	  {
	   return(width);
	  }
};
int main()
{
 rectangle rect;
 int l,b;
 clrscr();
 cout<<"\nEnter the length and breadth of a rectangle : ";
 cin>>l>>b;
 rect.setlength(20);
 rect.setwidth(10);
 cout<<"\nRectangle is "<<rect.getlength()<<" feet long ";
 cout<<"and "<<rect.getwidth()<<" feet wide";
 return 0;
}