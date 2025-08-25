// array of structure for displaying student details
#include<iostream>

#include<iomanip>
int main()
{
 typedef struct student
 {
  char name[10];
  int roll;
  int marks[3];
 }st;
 clrscr();
 st s[4]={{"Ram",12,90,95,97},
	{"Shyam",13,91,94,96}};
 for(int i=2;i<4;i++)
 {
  cout<<"\nEnter Student "<<i+1<<" Name : ";
  cin>>s[i].name;
  cout<<"Enter Student "<<i+1<<" Roll No. : ";
  cin>>s[i].roll;
  cout<<"Enter Student "<<i+1<<" Marks in 3 subjects : ";
   for(int j=0;j<3;j++)
   {
    cin>>s[i].marks[j];
   }
 }
 cout<<"\n\n\n"<<setw(21)<<"Name"<<setw(13)<<"Roll No."<<setw(13)<<"Sub1 Marks"<<setw(14)<<"Sub2 Marks"<<setw(15)<<"Sub3 Marks\n";
 for(i=0;i<4;i++)
 {
  cout<<"\nStudent "<<i+1<<setw(12)<<s[i].name;
  cout<<setw(12)<<s[i].roll;
  for(int j=0;j<3;j++)
  {
   cout<<setw(14)<<s[i].marks[j];
  }
  cout<<"\n";
 }
 return 0;
}
