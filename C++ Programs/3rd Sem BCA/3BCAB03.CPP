//program to check leap year
#include<iostream>

class leap
{
 private : int year;
 public : int checkyear();
	  void getdata();
	  void showdata();
};
int leap::checkyear()
{
 int r4=year%4,r100=year%100,r400=year%400;
 if((r4==0 && r100!=0) || (r400==0))
  return 1;
 else
  return 0;
};
void leap::getdata()
{
 cout<<"\nEnter the year : ";
 cin>>year;
}
void leap::showdata()
{
 if(checkyear())
  cout<<"\n"<<year<<" is a leap year";
 else
  cout<<"\n"<<year<<" is not a leap year";
}
int main()
{
 leap yr;
 clrscr();
 yr.getdata();
 yr.checkyear();
 yr.showdata();
 return 0;
}