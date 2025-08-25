//program to calculate area and circumference of a
//circle using inline function
#include<iostream>

const int pi=3.1416;
class circle
{
 public : inline float circum(float x)
	  {
	   return(2*pi*x);
	  }
	  inline float area(float x)
	  {
	   return(pi*x*x);
	  }
};
int main()
{
 circle c;
 float r;
 clrscr();
 cout<<"\nEnter the radius of a circle : ";
 cin>>r;
 cout<<"\nCircumference of a circle = "<<c.circum(r);
 cout<<"\nArea of a circle = "<<c.area(r);
 return 0;
}