// program for strings using pointers and find the length
#include<iostream>

#include<stdio.h> // for gets and puts function
int length(char *p)
{
 int count=0;
 while(*p!='\0')
 {
  count++;
  p++;
 }
 return count;
}
int main()
{
 char str[10];
 int len;
 clrscr();
 cout<<"\nEnter a String : ";
 gets(str);
 len=length(str);
 cout<<"The length of "<<str<<" = "<<len;
 return 0;
}