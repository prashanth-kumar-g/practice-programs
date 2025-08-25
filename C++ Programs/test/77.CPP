// program for strings using pointers and convert to uppercase
#include<iostream>

#include<stdio.h> // for gets and puts function
void uppercase(char *ptr)
{
 while(*ptr!='\0')
 {
  if(*ptr>=97 && *ptr<=122)
  {
   *ptr=*ptr-32;
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
 uppercase(str);
 cout<<"Coverted UpperCase String : "<<str;
 return 0;
}