/*program to perform string operations without using functions*/
#include<stdio.h>

#include<stdlib.h>
int len(char *);
int concat(char *,char *);
int reverse(char *);
int main()
{
 char s1[20],s2[20];
 int ch,length;
 
 while(1)
 {
  printf("\nMain Menu\n");
  printf("\n1: String length");
  printf("\n2: String concatenation");
  printf("\n3: String reverse");
  printf("\n4: Exit\n");
  printf("\nEnter your choice : ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: printf("Enter a String : ");
	   scanf("%s",&s1);
	   length=len(s1);
	   printf("length of %s is %d",s1,length);
	   printf("\n");
	   break;
   case 2: printf("Enter first String : ");
	   scanf("%s",&s1);
	   printf("Enter second String : ");
	   scanf("%s",&s2);
	   concat(s1,s2);
	   printf("concatenated string is %s",s1);
	   printf("\n");
	   break;
   case 3: printf("Enter a String : ");
	   scanf("%s",&s1);
	   printf("reversed string is : ");
	   reverse(s1);
	   printf("\n");
	   break;
   case 4: exit(0);
   default: printf("Error in choice");
	    printf("\n");
  }
 }
 return 0;
}
int len(char *s1)
{
 int length=0;
 while(*s1!='\0')
 {
  s1++;
  length++;
 }
 return(length);
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
int reverse(char *s1)
{
 if(*s1)
 {
  reverse(s1+1);
  printf("%c",*s1);
 }
}
