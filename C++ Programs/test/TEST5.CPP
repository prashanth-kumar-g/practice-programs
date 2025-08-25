#include<iostream>

int main()
{
 char ch1[20],ch2[20];
 clrscr();
 cout<<"\nEnter the string1 : ";
 cin>>ch1;
 cout<<"Enter the string2 : ";
 cin>>ch2;
 int i=0,flag=0;
 while(ch1[i]!='\0')
 {
  if(ch1[i]==ch2[i] || ch1[i]+32==ch2[i] || ch1[i]-32==ch2[i])
  {
   flag=1;
  }
  else
  {
   flag=0;
   break;
  }
  i++;
 }

 if(flag==1)
  cout<<"\nStrings are same";
 else
  cout<<"\nStrings are not same";
 return 0;
}
