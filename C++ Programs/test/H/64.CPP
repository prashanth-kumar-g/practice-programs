// program to print stars of square and rectangle
#include<iostream>

int main()
{
 int l,b;
 clrscr();
 cout<<"\nEnter the length : ";
 cin>>l;
 cout<<"Enter the breadth : ";
 cin>>b;
 cout<<"\n";
 for(int i=1;i<=b;i++)
 {
  for(int j=1;j<=l;j++)
  {
   cout<<"* ";
  }
  cout<<"\n";
 }
 return 0;
}

