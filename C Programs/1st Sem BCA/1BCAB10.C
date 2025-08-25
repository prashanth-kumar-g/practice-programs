/*program to convert all the characters in a string from uppercase
to lowercase*/
#include<stdio.h>

int main()
{
 char str[30];
 int i,length;
 
 printf("\nEnter the string : ");
 gets(str);
 length=strlen(str);
 for(i=0;i<length;i++)
 {
  if(str[i]>='A' && str[i]<='Z');
  str[i]=str[i]+32;
 }
 printf("converted string is : %s",str);
 return 0;
}