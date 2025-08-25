/*program to search for an element in an array using linear search*/
#include<stdio.h>

int main()
{
 int n,i,a[10],item,loc=0;
 
 printf("\nEnter the number of elements\n");
 scanf("%d",&n);
 printf("Enter the elements of the array\n");
 for(i=1;i<=n;i++)
 scanf("%d",&a[i]);
 printf("Enter the element whose position is to searched\n");
 scanf("%d",&item);
 for(i=1;i<=n;i++)
 {
  if(a[i]==item)
  {
   loc=i;
   break;
  }
 }
 if(loc==0)
  printf("Element %d is not found",item);
 else
  printf("Element %d is found in location %d",item,loc);
 return 0;
}











