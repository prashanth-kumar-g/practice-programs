//program to find area and volume of respective figures
//using function overloading
#include<iostream>

const double pi=3.1416;
class shape
{
 public : void measure(double r)
	  {
	   cout<<"Area of a circle : "<<pi*r*r<<endl;
	   cout<<"Volume of a sphere : "<<(4.00/3)*pi*r*r*r<<endl;
	  }
	  void measure(long l,int b, int h)
	  {
	   cout<<"Area of a rectangle : "<<l*b<<endl;
	   cout<<"Volume of a cuboid : "<<l*b*h<<endl;
	  }
	  void measure(float f)
	  {
	   cout<<"Area of a square : "<<f*f<<endl;
	   cout<<"Volume of a cube : "<<f*f*f<<endl;
	  }
};
int main()
{
 shape obj;
 int b,h;
 long l;
 float f;
 double r;
 clrscr();
 cout<<"\nCalculation of Area and Volume"<<endl;
 cout<<"\nEnter the radius of the circle : ";
 cin>>r;
 obj.measure(r);
 cout<<"\nEnter the length, breadth and height of the rectangle : ";
 cin>>l>>b>>h;
 obj.measure(l,b,h);
 cout<<"\nEnter the side of the square : ";
 cin>>f;
 obj.measure(f);
 return 0;
}
