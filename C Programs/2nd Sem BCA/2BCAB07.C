/*program to sort the array elements usig bubble sort*/
#include<stdio.h>

int main()
{
 int n,i,a[10],j,temp;
 
 printf("\nEnter the number of elements\n");
 scanf("%d",&n);
 printf("\nEnter the elements of the array\n");
 for(i=1;i<=n;i++)
 scanf("%d",&a[i]);
 printf("\n                     BUBBLE SORT                      \n");
 printf("\n*******************************************************\n");
 printf("\n   Original Order : ");
 for(i=1;i<=n;i++)
 printf("%d ",a[i]);
 printf("\n\n*******************************************************\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n-i;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
 printf("\n*******************************************************\n");
 printf("\n   Sorted Order : ");
 for(i=1;i<=n;i++)
 printf("%d ",a[i]);
 printf("\n\n*******************************************************\n");
 return 0;
}



