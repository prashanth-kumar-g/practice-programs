// passing pointers to structures as arguments
#include<iostream>

#include<string.h>
struct student
{
 char name[10];
 int roll;
};
void print(struct student *p)
{
 cout<<"\n\n name = "<<p->name;
 cout<<"\n roll no. = "<<p->roll;
}
int main()
{
 clrscr();

 struct student s1={"Ram",18};

 struct student s2,s3;

 strcpy(s2.name,"Shyam");
 s2.roll=21;

 cout<<"\nEnter Student 3 name : ";
 cin>>s3.name;
 cout<<"Enter Student 3 roll no. : ";
 cin>>s3.roll;

 cout<<"\n\nStudent Details are";
 print(&s1);
 print(&s2);
 print(&s3);

 return 0;
}
