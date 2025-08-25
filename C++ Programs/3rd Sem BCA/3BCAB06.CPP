//program to illustrate inheritance
#include<iostream>

class add
{
 public : int a,b;
	  void getdata()
	  {
	   cout<<"\nEnter two numbers : ";
	   cin>>a>>b;
	  }
};
class average:public add
{
 private : float sum,avg;
 public : void calculate()
	  {
	   getdata();
	   sum=a+b;
	   avg=sum/2;
	  }
	  void showdata()
	  {
	   cout<<"\nsum = "<<sum<<endl;
	   cout<<"average = "<<avg;
	  }
};
int main()
{
 average a1;
 clrscr();
 a1.calculate();
 a1.showdata();
 return 0;
}