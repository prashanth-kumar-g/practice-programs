/*program to find the transpose of a matrix*/
#include<stdio.h>

int main()
{
 int m,n,i,j,matrix[10][10],transpose[10][10];
 
 printf("\nEnter the order of the matrix\n");
 scanf("%d %d",&m,&n);
 printf("Enter the elements of the matrix\n");
 for(i=1;i<=m;i++)
 for(j=1;j<=n;j++)
 scanf("%d",&matrix[i][j]);
 for(i=1;i<=m;i++)
 for(j=1;j<=n;j++)
 transpose[j][i]=matrix[i][j];
 printf("Transpose of the matrix is\n");
 for(i=1;i<=m;i++)
 {
  for(j=1;j<=n;j++)
  {
   printf("%d ",transpose[i][j]);
  }
  printf("\n");
 }
 return 0;
}












