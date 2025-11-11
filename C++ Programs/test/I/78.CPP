// program for strings using pointers and reverse the string
#include<iostream>

#include<stdio.h> // for gets and puts function
int length(char *ptr)
{
 int count=0;
 while(*ptr!='\0')
 {
  count++;
  ptr++;
 }
 return count;
}
void reverse(char *ptr)
{
 int len=length(ptr);
 char temp;
 for(int i=0;i<len/2;i++)
 {
  temp=ptr[i];            // temp=*(ptr+i);
  ptr[i]=ptr[len-i-1];    // *(ptr+i)=*(ptr+len-i-1);
  ptr[len-i-1]=temp;      // *(ptr+len-i-1)=temp;
 }
}
int main()
{
 char str[10];
 clrscr();
 cout<<"\nEnter a String : ";
 gets(str);
 reverse(str);
 cout<<"Reversed String is : "<<str;
 return 0;
}