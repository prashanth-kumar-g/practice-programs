// program for strings using pointers and extract a substring
#include<iostream>

#include<stdio.h> // for gets and puts function
void extract_substring(char *ptr, int pos, int len, char *sub_ptr)
{
 int i=pos-1;
 while(len!=0)
 {
  *sub_ptr=*(ptr+i);  // *sub_str=ptr[i];
  i++;
  len--;
  sub_ptr++;
 }
 // or using for loop
 /*for(int i=pos-1;len!=0;i++,len--)
 {
  *sub_ptr=*(ptr+i);  // *sub_str=ptr[i];
  sub_ptr++;
 }*/
 *sub_ptr='\0';
}
int main()
{
 char str[10],sub_str[10];
 int len,pos;
 clrscr();
 cout<<"\nEnter a String : ";
 gets(str);
 cout<<"Enter the position and length : ";
 cin>>pos>>len;
 extract_substring(str,pos,len,sub_str);
 cout<<"Extracted Substring is : "<<sub_str;
 return 0;
}