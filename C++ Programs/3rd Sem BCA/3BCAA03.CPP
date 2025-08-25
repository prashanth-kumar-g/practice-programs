//program to swap two numbers using friend function
#include<iostream>

class sample
{
 private : int x,y;
 public : void getdata(int a,int b)
	  {
	   x=a;
	   y=b;
	  }
	  void showdata()
	  {
	   cout<<"x = "<<x<<endl;
	   cout<<"y = "<<y<<endl;
	  }
	  friend void swap(sample &s);
};
void swap(sample &s)
{
 int temp;
 temp=s.x;
 s.x=s.y;
 s.y=temp;
}
int main()
{
 sample s1;
 int x,y;
 clrscr();
 cout<<"\nEnter two numbers : ";
 cin>>x>>y;
 s1.getdata(x,y);
 cout<<"\nBefore Swapping"<<endl;
 s1.showdata();
 swap(s1);
 cout<<"\nAfter Swapping"<<endl;
 s1.showdata();
 return 0;
}