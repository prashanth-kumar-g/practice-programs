// simple program for strings
#include<iostream>

#include<stdio.h> // for gets and puts function
void display(char str[])
{
 int i=0;
 while(str[i]!='\0')   // or cout<<str;  or  puts(str);
 {
  cout<<str[i];
  i++;
 }
}
int main()
{
 char str[10];
 clrscr();
 cout<<"\nEnter a String : ";
 gets(str); // cin>>str;
 display(str);
 return 0;
}