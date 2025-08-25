#include<iostream>

int main()
{
 char ch1[6],ch2[6];
 clrscr();
 cout<<"\nEnter the string1 : ";
 cin>>ch1;
 int i=0,len1=0;
 while(ch1[i]!='\0')
 {
  len1++;
  i++;
 }
 cout<<"Enter the string2 : ";
 cin>>ch2;
 i=0;
 int len2=0;
 while(ch2[i]!='\0')
 {
  len2++;
  i++;
 }
 cout<<"\nlength1 = "<<len1;
 cout<<"\nlength2 = "<<len2;

 char ch3[12];
 i=0;
 while(ch1[i]!='\0')
 {
  ch3[i]=ch1[i];
  i++;
 }
 i=0;
 int j=len1;
 while(ch2[i]!='\0')
 {
  ch3[j]=ch2[i];
  i++;
  j++;
 }
 ch3[j]='\0';
 cout<<"\n"<<ch3;
 return 0;
}