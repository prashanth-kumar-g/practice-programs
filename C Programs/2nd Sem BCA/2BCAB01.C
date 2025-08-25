/*program to compare two strings using pointers*/
#include<stdio.h>

int compare(char *s1,char *s2);
int main()
{
 char s1[20],s2[20];
 int res;
 
 printf("\nEnter the first string : ");
 scanf("%s",&s1);
 printf("Enter the second string : ");
 scanf("%s",&s2);
 res=compare(s1,s2);
 if(res==0)
 printf("two strings are identical");
 else
 printf("two strings are not the same");
 return 0;
 return 0;
}
int compare(char *s1,char *s2)
{
 while(*s1==*s2)
 {
  if(*s1=='\0')
  return(0);
  s1++;
  s2++;
 }
 return(*s1-*s2);
}







