/*program to product of two matrices*/
#include<stdio.h>

int main()
{
 int matrix1[10][10],matrix2[10][10],multiply[10][10];
 int m,n,p,q,i,j,k,sum=0;
 
 printf("\nEnter the no. of rows and columns for 1st matrix\n");
 scanf("%d %d",&m,&n);
 printf("Enter the elements for 1st matrix\n");
 for(i=1;i<=m;i++)
 for(j=1;j<=n;j++)
 scanf("%d",&matrix1[i][j]);
 printf("\nEnter the no. of rows and columns for 2nd matrix\n");
 scanf("%d %d",&p,&q);
 printf("Enter the elements for 1st matrix\n");
 for(i=1;i<=p;i++)
 for(j=1;j<=q;j++)
 scanf("%d",&matrix2[i][j]);
 for(i=1;i<=m;i++)
 {
  for(j=1;j<=p;j++)
  {
   for(k=1;k<=q;k++)
   {
    sum=sum+matrix1[i][k]*matrix2[k][j];
   }
   multiply[i][j]=sum;
   sum=0;
  }
 }
 printf("\nThe product of two matrices is\n");
 for(i=1;i<=m;i++)
 {
  for(j=1;j<=q;j++)
  {
   printf("%5d",multiply[i][j]);
  }
  printf("\n");
 }
 return 0;
}



