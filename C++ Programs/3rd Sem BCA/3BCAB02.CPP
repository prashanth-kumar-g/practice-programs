//program for employee details
#include<iostream>

#include<iomanip>
class employee
{
 private : char name[30];
	   int id;
	   char number[10];
	   float salary;
	   float pf;
	   float netsalary;
 public : void getdata();
	  void putdata();
};
void employee::getdata()
{
 cout<<"\nEnter the Employee Details"<<endl;
 cout<<" Employee Name : ";
 cin>>name;
 cout<<" Employee Id : ";
 cin>>id;
 cout<<" Employee Number : ";
 cin>>number;
 cout<<" Employee Salary : ";
 cin>>salary;
 cout<<" Employee PF : ";
 cin>>pf;
}
void employee::putdata()
{
 netsalary=salary-pf;
 cout<<"\nThe Employee Details are"<<endl;
 cout<<" Employee  Name = "<<name<<endl;
 cout<<" Employee Id = "<<id<<endl;
 cout<<" Employee Number = "<<number<<endl;
 cout<<" Employee Salary = "<<salary<<endl;
 cout<<" Employee PF = "<<pf<<endl;
 cout<<" Employee Net Salary = "<<netsalary;
}
int main()
{
 employee emp;
 clrscr();
 emp.getdata();
 emp.putdata();
 return 0;
}