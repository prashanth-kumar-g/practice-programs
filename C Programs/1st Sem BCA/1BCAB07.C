/*program to count the number of even, odd, positive and negative
numbers out of 10 given numbers*/
#include<stdio.h>

int main()
{
 int a[10],even=0,odd=0,pos=0,neg=0,i;
 
 printf("\nEnter 10 numbers\n");
 for(i=1;i<=10;i++)
 {
  scanf("%d",&a[i]);
  a[i]<0?(neg++):(pos++);
  (a[i]%2==0)?(even++):(odd++);
 }
 printf("\nPositive Number = %d",pos);
 printf("\nNegative Number = %d",neg);
 printf("\nEven Number = %d",even);
 printf("\nOdd Number = %d",odd);
 return 0;
}
