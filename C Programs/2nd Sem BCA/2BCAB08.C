/*program to insert an element into the array*/
#include<stdio.h>

int main()
{
 int a[10],i,n,ele,pos;
 
 printf("\nEnter the size of the array\n");
 scanf("%d",&n);
 printf("Enter the elements of the array\n");
 for(i=1;i<=n;i++)
 scanf("%d",&a[i]);
 printf("Enter the element to be inserted and its position\n");
 scanf("%d %d",&ele,&pos);
 printf("\nARRAY BEFORE INSERTION\n");
 for(i=1;i<=n;i++)
 printf("%d ",a[i]);
 for(i=n;i>=pos;i--)
 a[i+1]=a[i];
 a[pos]=ele;
 printf("\n\nARRAY AFTER INSERTION\n");
 for(i=1;i<=n+1;i++)
 printf("%d ",a[i]);
 return 0;
}















