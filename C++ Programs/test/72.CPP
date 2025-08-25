// program for strings using pointers and copy string
#include<iostream>

#include<stdio.h> // for gets and puts function
void copy(char *ptr2, char *ptr1)
{
 while(*ptr1!='\0')
 {
  *ptr2=*ptr1;
  ptr1++;
  ptr2++;
 }
 *ptr2='\0';
}
int main()
{
 char str1[10],str2[10];
 clrscr();
 cout<<"\nEnter the String 1 : ";
 gets(str1);
 copy(str2,str1);
 cout<<"The String 1 is "<<str1;
 cout<<"\nThe Copied String 2 is "<<str2;
 return 0;
}