// passing structure member as argument using call by refernce
#include<iostream>

#include<string.h>
void assign_s1(char *,int *);
void assign_s2(char *,int *);
void input_s3(char *,int *);
int main()
{
 struct student
 {
  char ch;
  int roll;
 };
 clrscr();

 struct student s1,s2,s3;

 assign_s1(&(s1.ch),&(s1.roll));
 assign_s2(&(s2.ch),&(s2.roll));
 input_s3(&(s3.ch),&(s3.roll));

 cout<<"\n\nStudent 1 Details\n";
 cout<<" favourite alphabet = "<<s1.ch;
 cout<<"\n favourite number = "<<s1.roll;

 cout<<"\n\nStudent 2 Details\n";
 cout<<" favourite alphabet = "<<s2.ch;
 cout<<"\n favourite number = "<<s2.roll;

 cout<<"\n\nStudent 3 Details\n";
 cout<<" favourite alphabet = "<<s3.ch;
 cout<<"\n favourite number = "<<s3.roll;

 return 0;
}
void assign_s1(char *n,int *r)
{
 *n='R';
 *r=18;
}
void assign_s2(char *n,int *r)
{
 strcpy(n,"S");
 *r=21;
}
void input_s3(char *n,int *r)
{
 cout<<"\nEnter student 3 favourite alphabet : ";
 cin>>*n;
 cout<<"Enter student 3 favourite number : ";
 cin>>*r;
}