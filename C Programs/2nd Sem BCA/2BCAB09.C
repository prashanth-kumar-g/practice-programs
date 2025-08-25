/*program to find whether a given matrix is sparse matrix or not*/
#include<stdio.h>

int main()
{
 int matrix[10][10];
 int i,j,m,n;
 int sparse_counter=0;
 
 printf("\nEnter the order of the matrix\n");
 scanf("%d %d",&m,&n);
 printf("Enter the elements of the matrix\n");
 for(i=1;i<=m;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&matrix[i][j]);
   if(matrix[i][j]==0)
   {
    ++sparse_counter;
   }
  }
 }
 if(sparse_counter>((m*n)/2))
  printf("The given matrix is a sparse matrix!!!");
 else
  printf("The given matrix is not a sparse matrix");
 printf("\nThere are %d number of zeroes",sparse_counter);
 return 0;
}









