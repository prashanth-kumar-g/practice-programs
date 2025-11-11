// program for strings and functions in "string.h" library
#include<iostream>

#include<stdio.h> // for gets and puts function
#include<string.h>
int main()
{
 char str1[10],str2[10],temp[10];
 clrscr();
 cout<<"\nEnter the String 1 : ";
 gets(str1);
 cout<<"Enter the String 2 : ";
 gets(str2);
 cout<<"\nLength of String 1 : "<<strlen(str1);
 cout<<"\nString 1 copied to Temp : "<<strcpy(temp,str1);
 cout<<"\nComparing String 1 and String 2 : "<<strcmp(str1,str2);
 cout<<"\nComparing String 1 and String 2 (no case-sensitive) : "<<strcmpi(str1,str2);
 cout<<"\nLowercase of String 1 : "<<strlwr(str1);
 cout<<"\nUppercase of String 1 : "<<strupr(str1);
 cout<<"\nReverse of String 1 : "<<strrev(str1);
 cout<<"\nConcatenation of String 1 and String 2 : "<<strcat(temp,str2);
 return 0;
}