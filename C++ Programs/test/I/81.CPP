// program for strings using pointers and insert substring in a string
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
void insert_substring(char *ptr, char *sub_ptr, int pos)
{
 int len1=length(ptr);
 int len2=length(sub_ptr);
 for(int i=len1+len2-1;i>pos-1;i--)
 {
  *(ptr+i)=*(ptr+i-len2);   // ptr[i]=ptr[i-len2];
 }
 *(ptr+len1+len2)='\0';   // ptr[len1+len2]='\0';
 i=pos;
 while(len2!=0)
 {
  *(ptr+i)=*sub_ptr;   // ptr[i]=*sub_ptr;
  sub_ptr++;
  len2--;
  i++;
 }
}
int main()
{
 char str[20],sub_str[10];
 int pos;
 clrscr();
 cout<<"\nEnter a String : ";
 gets(str);
 cout<<"Enter the substring to be added : ";
 gets(sub_str);
 cout<<"Enter the position : ";
 cin>>pos;
 insert_substring(str,sub_str,pos);
 cout<<"String after inserting Substring : "<<str;
 return 0;
}