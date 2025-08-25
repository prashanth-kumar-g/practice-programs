// program to perform basic arithmetic operations
#include<iostream>

int main()
{
 float a,b;
 clrscr();
 cout<<"\nEnter two numbers : ";
 cin>>a>>b;
 cout<<"\n"<<a<<" + "<<b<<" = "<<a+b;
 cout<<"\n"<<a<<" - "<<b<<" = "<<a-b;
 cout<<"\n"<<a<<" * "<<b<<" = "<<a*b;
 cout<<"\n"<<a<<" / "<<b<<" = "<<a/b;
 cout<<"\n"<<a<<" % "<<b<<" = "<<(int)a%(int)b;
 return 0;
}
