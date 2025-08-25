// program for function template
#include<iostream>

template<class T>
void swap(T &a,T &b)
{
 T temp;
 temp=a;
 a=b;
 b=temp;
}
template<class T>
void display(T a,T b)
{
 cout<<"a = "<<a<<"  b = "<<b;
}
int main()
{
 clrscr();
 int choice;
 cout<<"\nWhich type for swap (int-1, float-2, char-3, double-4) : ";
 cin>>choice;
 // using if and else
 /* if(choice==1)
 {
  int a,b;
  cout<<"\nEnter two numbers : ";
  cin>>a>>b;
  cout<<"\nBefore Swapping : ";
  display(a,b);
  swap(a,b);
  cout<<"\n\nAfter Swapping :  ";
  display(a,b);
 }
 else if(choice==2)
 {
  float a,b;
  cout<<"\nEnter two numbers : ";
  cin>>a>>b;
  cout<<"\nBefore Swapping : ";
  display(a,b);
  swap(a,b);
  cout<<"\n\nAfter Swapping :  ";
  display(a,b);
 }
 else if(choice==3)
 {
  char a,b;
  cout<<"\nEnter two numbers : ";
  cin>>a>>b;
  cout<<"\nBefore Swapping : ";
  display(a,b);
  swap(a,b);
  cout<<"\n\nAfter Swapping :  ";
  display(a,b);
 }
 else if(choice==4)
 {
  double a,b;
  cout<<"\nEnter two numbers : ";
  cin>>a>>b;
  cout<<"\nBefore Swapping : ";
  display(a,b);
  swap(a,b);
  cout<<"\n\nAfter Swapping :  ";
  display(a,b);
 }
 else
 {
  cout<<"\nInvalid Choice";
 } */

 // using switch case
 /* switch(choice)
 {
  case 1 : int a1,b1;
	   cout<<"\nEnter two numbers : ";
	   cin>>a1>>b1;
	   cout<<"\nBefore Swapping : ";
	   display(a1,b1);
	   swap(a1,b1);
	   cout<<"\n\nAfter Swapping :  ";
	   display(a1,b1);
	   break;
  case 2 : float a2,b2;
	   cout<<"\nEnter two numbers : ";
	   cin>>a2>>b2;
	   cout<<"\nBefore Swapping : ";
	   display(a2,b2);
	   swap(a2,b2);
	   cout<<"\n\nAfter Swapping :  ";
	   display(a2,b2);
	   break;
  case 3 : char a3,b3;
	   cout<<"\nEnter two numbers : ";
	   cin>>a3>>b3;
	   cout<<"\nBefore Swapping : ";
	   display(a3,b3);
	   swap(a3,b3);
	   cout<<"\n\nAfter Swapping :  ";
	   display(a3,b3);
	   break;
  case 4 : double a4,b4;
	   cout<<"\Enter two numbers : ";
	   cin>>a4>>b4;
	   cout<<"\nBefore Swapping : ";
	   display(a4,b4);
	   swap(a4,b4);
	   cout<<"\n\nAfter Swapping :  ";
	   display(a4,b4);
	   break;
  default : cout<<"\nInvalid Choice";
 }*/
 return 0;
}
