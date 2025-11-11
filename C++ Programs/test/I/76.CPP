// program for strings using pointers and convert to lowercase
#include<iostream>

#include<stdio.h> // for gets and puts function
void lowercase(char *ptr)
{
 while(*ptr!='\0')
 {
  if(*ptr>=65 && *ptr<=90)
  {
   *ptr=*ptr+32;
  }
  ptr++;
 }
}
int main()
{
 char str[10];
 clrscr();
 cout<<"\nEnter a String : ";
 gets(str);
 lowercase(str);
 cout<<"Coverted LowerCase String : "<<str;
 return 0;
}