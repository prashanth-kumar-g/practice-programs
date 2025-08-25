/*program to search for an element in an array using binary search*/
#include<stdio.h>

int binsearch(int,int [],int);
int main()
{
 int a[10],i,item,n;
 
 printf("\nEnter the size of array\n");
 scanf("%d",&n);
 printf("Enter the elements of the array\n");
 for(i=1;i<=n;i++)
 {
  printf("Element[%d] = ",i);
  scanf("%d",&a[i]);
 }
 printf("Enter the item to be searched\n");
 scanf("%d",&item);
 binsearch(n,a,item);
 return 0;
}
int binsearch(int n,int a[],int item)
{
 int low=1,high=n,mid;
 while(low<=high)
 {
  mid=(low+high)/2;
  if(item==a[mid]);
  {
   printf("item %d is found at location %d",item,mid);
   return 0;
  }
  if(item>a[mid])
  {
   low=mid+1;
  }
  else
  {
   high=mid-1;
  }
 }
 printf("item %d is not found",item);
 return 0;
}























