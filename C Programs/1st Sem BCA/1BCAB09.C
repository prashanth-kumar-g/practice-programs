/*program to find the frequency of a specified character in a given string*/
#include<stdio.h>

#include<string.h>
int main()
{
 char txt[30],ch;
 int i,length,count=0;
 
 printf("\nEnter the string : ");
 gets(txt);
 printf("Enter a character to be searched : ");
 scanf("%c",&ch);
 length=strlen(txt);
 for(i=1;i<=length;i++)
 {
  if(txt[i]==ch)
  count=count+1;
 }
 if(count>0)
  printf("%c occurs %d times",ch,count);
 else
  printf("%c is not available in the string",ch);
 return 0;
}