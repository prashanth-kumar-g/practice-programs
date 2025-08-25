/*program to copy strings using pointers*/
#include<stdio.h>

int copy(char *,char *);
main()
{
 char s1[20],s2[20];
 
 printf("\nEnter the string\n");
 gets(s1);
 copy(s2,s1);
 printf("string1 is : %s",s1);
 printf("\nstring2 is : %s",s2);
 return 0;
}
int copy(char *s2,char *s1)
{
 while(*s1!='\0')
 {
  *s2=*s1;
  s1++;
  s2++;
 }
 *s2='\0';
 return 0;
}














