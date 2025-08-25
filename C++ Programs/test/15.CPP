// array of structure
#include<iostream>

int main()
{
 struct std
 {
  char name[10];
  int roll;
 };
 clrscr();
 struct std s[4];
 for(int i=1;i<=4;i++)
 {
  cout<<"\nEnter Student "<<i<<" Name : ";
  cin>>s[i].name;
  cout<<"Enter Student "<<i<<" Roll No. : ";
  cin>>s[i].roll;
 }
 for(i=1;i<=4;i++)
 {
  cout<<"\n\nStudent "<<i<<" Name is : "<<s[i].name;
  cout<<"\nStudent "<<i<<" Roll No. is : "<<s[i].roll;
 }
 return 0;
}


