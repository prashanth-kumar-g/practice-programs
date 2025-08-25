/*program to concatenate two strings using pointers*/
#include<stdio.h>

int concat(char *,char *);
int main()
{
 char first[25],second[25];
 
 printf("\nEnter the first string : ");
 gets(first);
 printf("Enter the second string : ");
 gets(second);
 concat(first,second);
 printf("concatenated string is : %s",first);
 return 0;
}
int concat(char *s1,char *s2)
{
 while(*s1!='\0')
 s1++;
 while(*s2!='\0')
 {
  *s1=*s2;
  s1++;
  s2++;
 }
 *s1='\0';
 return 0;
}