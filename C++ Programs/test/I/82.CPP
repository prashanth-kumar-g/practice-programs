// program for strings using pointers and pattern searching
#include<iostream>

#include<stdio.h> // for gets and puts function
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
int pattern_searching(char *ptr, char *sub_ptr)
{
 int len1=length(ptr);
 int len2=length(sub_ptr);
 int loc=-1,temp_i;
 for(int i=0;i<=len1-len2;i++)
 {
   int start_pos=temp_i=i;
   for(int j=0;j<len2;j++)
   {
    if(ptr[temp_i]==sub_ptr[j])
    {
     loc=start_pos;
     temp_i++;
    }
    else
    {
     loc=-1;
     break;
    }
   }
   if(j==len2)
   {
    return loc+1;  // since for users understanding (location starts from 1)
   }
 }
 return loc;
}
int main()
{
 char str[20],sub_str[10];
 int loc;
 clrscr();
 cout<<"\nEnter a String : ";
 gets(str);
 cout<<"Enter the pattern to be searched : ";
 gets(sub_str);
 loc=pattern_searching(str,sub_str);
 if(loc==-1)
 {
  cout<<"The pattern does not exist in the String";
 }
 else
 {
  cout<<"The pattern appears from the location : "<<loc;
 }
 return 0;
}