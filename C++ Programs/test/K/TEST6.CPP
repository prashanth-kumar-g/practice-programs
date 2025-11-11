#include<iostream>

#include<stdio.h>
int main()
{
 char str[20];
 clrscr();
 cout<<"\nEnter a string : ";
 gets(str);
 int i,len=0;
 i=0;
 while(str[i]!='\0')
 {
  len++;
  i++;
 }
 cout<<"\n"<<len;
 int j;
 char temp;
 for(i=0;i<len-1;i++)
 {
  for(j=0;j<len-i-1;j++)
  {
   if(str[j]>str[j+1])
   {
    temp=str[j];
    str[j]=str[j+1];
    str[j+1]=temp;
   }
  }
 }
 cout<<"\n"<<str;
 i=0;
 j=0;
 while(str[i]!='\0')
 {
  if(str[i]!=' ')
  {
   str[j]=str[i];
   j++;
  }
  i++;
 }
 str[j]='\0';
 cout<<"\n"<<str;
 char temp1,temp2;
 int count,max=0;
 i=0;
 while(str[i]!='\0')
 {
  temp1=str[i];
  count=0;
  j=0;
  while(str[j]!='\0')
  {
   if(temp1==str[j])
   {
    count++;
   }
   j++;
  }
  if(count>max)
  {
   temp2=temp1;
   max=count;
  }
  i++;
 }
 cout<<"\n"<<temp2;
 return 0;
}