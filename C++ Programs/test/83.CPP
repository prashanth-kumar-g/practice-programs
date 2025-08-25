// program for strings using pointers and dynamic memory allocation
// and find if string is a palindrome
#include<iostream>

#include<stdio.h> // for gets and puts function
#include<stdlib.h> // for malloc function
int length(char *p)
{
 int count=0;
 while(*p!=0)
 {
  p++;
  count++;
 }
 return count;
}
int palindrome(char *ptr)
{
 char *rev_str=(char *)malloc(10*sizeof(char));
 int len=length(ptr);
 int j=0;
 for(int i=len-1;i>=0;i--)
 {
  *(rev_str+j)=*(ptr+i);  // rev_str[j]=ptr[i];
  j++;
 }
 rev_str[j]='\0';     // *(rev_str+j)='\0';
 int flag;
 for(i=0;i<len;i++)
 {
  if(ptr[i]==rev_str[i])   // *(ptr+i)==*(rev_str+i)
  {
   flag=1;
  }
  else
  {
   return 0;
  }
 }
 free(rev_str);
 return flag;
}
int main()
{
 char *str=(char *)malloc(10*sizeof(char));
 int res;
 clrscr();
 cout<<"\nEnter a String : ";
 gets(str);
 res=palindrome(str);
 if(res==1)
 {
  cout<<str<<" is a palindrome";
 }
 else
 {
  cout<<str<<" is not a palindrome";
 }
 free(str);
 return 0;
}