// program for strings using pointers and compare strings (no case-sensitive)
#include<iostream>

#include<stdio.h> // for gets and puts function
int compare(char *ptr1, char *ptr2)
{
 int flag;
 while(*ptr1!='\0')
 {
  if(*ptr1==*ptr2 || *ptr1+32==*ptr2 || *ptr1-32==*ptr2)
  {
   flag=1;
  }
  else
  {
   return 0;
  }
  ptr1++;
  ptr2++;
 }
 return flag;
}
int main()
{
 char str1[10],str2[10];
 int res;
 clrscr();
 cout<<"\nEnter the String 1 : ";
 gets(str1);
 cout<<"Enter the String 2 : ";
 gets(str2);
 res=compare(str1,str2);
 if(res==1)
 {
  cout<<"Strings are equal";
 }
 else
 {
  cout<<"Strings are not equal";
 }
 return 0;
}