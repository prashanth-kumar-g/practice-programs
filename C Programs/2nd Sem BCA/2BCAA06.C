/*program for towers of hanoi using recursion*/
#include<stdio.h>

int towers(int,char,char,char);
int main()
{
 int n;
 
 printf("\nEnter the number of disks : ");
 scanf("%d",&n);
 towers(n,'A','C','B');
 return 0;
}
int towers(int n,char source,char dest,char aux)
{
 if(n==1)
 {
  printf("\nMove disk 1 from peg %c to peg %c",source,dest);
  return 0;
 }
 towers(n-1,source,aux,dest);
 printf("\nMove disk %d from peg %c to peg %c",n,source,dest);
 towers(n-1,aux,dest,source);
}

















