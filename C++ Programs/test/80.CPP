// program for strings using pointers and replace in a string
#include<iostream>

#include<stdio.h> // for gets and puts function
void replace(char *ptr, char ch1, char ch2)
{
 while(*ptr!='\0')
 {
  if(*ptr==ch1)
  {
   *ptr=ch2;
  }
  ptr++;
 }
}
int main()
{
 char str[10],ch1,ch2;
 clrscr();
 cout<<"\nEnter a String : ";
 gets(str);
 cout<<"Enter the character to be replaced : ";
 cin>>ch1;
 cout<<"Enter the character to be added : ";
 cin>>ch2;
 replace(str,ch1,ch2);
 cout<<"Extracted Substring is : "<<str;
 return 0;
}