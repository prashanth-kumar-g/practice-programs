// program for pointers, dynamic memory allocation and
// passing arrays as parameters
#include<iostream>

#include<stdlib.h>
void sortArray(int p[], int n)   // void sortArray(int *p, int n)
{
 for(int i=0;i<n-1;i++)
 {
  for(int j=0;j<n-i-1;j++)
  {
   if(p[j]>p[j+1])
   {
    int temp=p[j];
    p[j]=p[j+1];
    p[j+1]=temp;
   }
  }
 }
}
int main()
{
 clrscr();
 int n;
 int *ptr;
 cout<<"Enter the size : ";
 cin>>n;
 ptr=(int *)malloc(n*sizeof(int));
 cout<<"\nEnter the array elements : ";
 for(int i=0;i<n;i++)
 {
  cin>>ptr[i];
 }
 sortArray(ptr,n);
 cout<<"\nArray elements in Ascending Order : ";
 for(i=0;i<n;i++)
 {
  cout<<ptr[i]<<" ";
 }
 cout<<"\n\nArray elements in Descending Order : ";
 for(i=n-1;i>=0;i--)
 {
  cout<<ptr[i]<<" ";
 }
 return 0;
}