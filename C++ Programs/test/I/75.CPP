// program for strings using pointers and concatenate strings
#include<iostream>

#include<stdio.h> // for gets and puts function
void concat(char *ptr3, char *ptr1, char *ptr2)
{
 while(*ptr1!='\0')
 {
  *ptr3=*ptr1;
  ptr1++;
  ptr3++;
 }
 while(*ptr2!='\0')
 {
  *ptr3=*ptr2;
  ptr2++;
  ptr3++;
 }
 *ptr3='\0';
}
int main()
{
 char str1[10],str2[10],str3[20];
 clrscr();
 cout<<"\nEnter the String 1 : ";
 gets(str1);
 cout<<"Enter the String 2 : ";
 gets(str2);
 concat(str3,str1,str2);
 cout<<"The Concatenated String is "<<str3;
 return 0;
}