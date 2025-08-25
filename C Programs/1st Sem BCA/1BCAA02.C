/*menu driven c program using switch statement to find factorial or
sum of digits of a given number*/
#include<stdio.h>

int sum_of_digits();
int fact_of_num();
int main()
{
 int choice;
 
 printf("\nMenu");
 printf("\n1.finding the sum of digits of an number");
 printf("\n2.finding the factorial of a number");
 printf("\n\nEnter your choice : ");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1 : sum_of_digits();
	   break;
  case 2 : fact_of_num();
	   break;
  default : printf("\nwrong choice");
	    break;
 }
 
}
int sum_of_digits()
{
 int num,digit,sum;
 printf("\nEnter the number : ");
 scanf("%d",&num);
 sum=0;
 while(num>0)
 {
  digit=num%10;
  sum=sum+digit;
  num=num/10;
 }
 printf("sum = %d",sum);
}
int fact_of_num()
{
 int num,fact,i;
 printf("\nEnter a number : ");
 scanf("%d",&num);
 fact=1;
 for(i=1;i<=num;i++)
 {
  fact=fact*i;
 }
 printf("%d! = %d",num,fact);
 return 0;
}
