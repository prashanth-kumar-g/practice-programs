/*program to arrange the given number in Ascending and Descending Order*/
#include<stdio.h>

int main()
{
 int n,i,j,a[10],temp;
 
 printf("\nEnter the number of elements\n");
 scanf("%d",&n);
 printf("Enter the elements\n");
 for(i=1;i<=n;i++)
 scanf("%d",&a[i]);
 for(i=1;i<=n;i++)
 {
  for(j=i;j<=n;j++)
  {
   if(a[i]>a[j])
   {
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
   }
  }
 }
 printf("\nAscending Order\n");
 for(i=1;i<=n;i++)
 {
  printf("%d ",a[i]);
 }
 printf("\nDescending Order\n");
 for(i=n;i>=1;i--)
 {
  printf("%d ",a[i]);
 }
 return 0;
}