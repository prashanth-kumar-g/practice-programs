#include<iostream>

int main()
{
 int a[5]={5,4,1,2,3};
 int i,j,temp;
 clrscr();
 cout<<"\n given array : ";
 for(i=0;i<5;i++)
 {
  cout<<a[i]<<" ";
 }
 for(i=0;i<5-1;i++)
 {
  for(j=0;j<5-i-1;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
 cout<<"\n sorted array : ";
 for(i=0;i<5;i++)
 {
  cout<<a[i]<<" ";
 }
 return 0;
}