#include<iostream>

int max(int x,int y)
{
 if(x>y)
  return x;
 else
  return y;
}
int max_product(int arr[],int n)
{
 if(n<4)
  return -1;
 int max_product=0;
 for(int i=0;i<n-3;i++)
 {
  for(int j=i+1;j<n-2;j++)
  {
   for(int k=j+1;k<n-1;k++)
   {
    for(int l=k+1;l<n;l++)
    {
     max_product=max(max_product,arr[i]*arr[j]*arr[k]*arr[l]);
    }
   }
  }
 }
 return max_product;
}
int main()
{
 int arr[5]={10,3,5,6,20};
 clrscr();
 int n=sizeof(arr)/sizeof(arr[0]);
 int max=max_product(arr,n);
 if (max==-1)
  cout<<"\nNo Quadruple exists";
 else
  cout<<"\nMaximum product is : " <<max;
 return 0;
}
