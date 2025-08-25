#include<iostream>

int main()
{
 int arr[5]={10,3,6,5,20};
 int n=sizeof(arr)/sizeof(arr[0]);
 int i,j,temp;
 clrscr();
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(arr[j]<arr[j+1])
   {
    temp=arr[j];
    arr[j]=arr[j+1];             
    arr[j+1]=temp;
   }
  }
 }
 int max_product=1;
 for(i=0;i<4;i++)
 {
  max_product=max_product*arr[i];
 }
 if(n<4)
  cout<<"\nNo Quadruple exists";
 else
  cout<<"\nMaximum product is : " <<max_product;
 return 0;
}