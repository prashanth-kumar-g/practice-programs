// passing structure member as argument using call by value
#include<iostream>

#include<string.h>
void print_s1(char [],int);
void print_s2(char [],int);
void print_s3(char [],int);
int main()
{
 struct student
 {
  char name[10];
  int roll;
 };
 clrscr();

 struct student s1={"Ram",18};

 struct student s2,s3;

 strcpy(s2.name,"Shyam");

 s2.roll=21;
 cout<<"\nEnter student 3 name : ";
 cin>>s3.name;
 cout<<"Enter student 3 roll no. : ";
 cin>>s3.roll;

 print_s1(s1.name,s1.roll);
 print_s2(s2.name,s2.roll);
 print_s3(s3.name,s3.roll);

 return 0;
}
void print_s1(char name[],int roll)
{
 cout<<"\n\nStudent 1 Details\n";
 cout<<" name = "<<name;
 cout<<"\n roll no. = "<<roll;
}
void print_s2(char name[],int roll)
{
 cout<<"\n\nStudent 2 Details\n";
 cout<<" name = "<<name;
 cout<<"\n roll no. = "<<roll;
}
void print_s3(char name[],int roll)
{
 cout<<"\n\nStudent 3 Details\n";
 cout<<" name = "<<name;
 cout<<"\n roll no. = "<<roll;
}