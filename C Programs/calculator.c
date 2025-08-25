#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int ch;
	double a,b;
	while(1)
	{
		printf("\n-------------------------------------------------------------");
		printf("\n                  SIMPLE CALCULATOR                          ");
		printf("\n                 -------------------                         ");
		printf("\n    1) Addition    2) Subtraction    3) Multiplication       ");
		printf("\n    4) Division    5) Remainder      6) Quotient             ");
		printf("\n    7) Exponent    8) Nth-Root       9) Exit                 ");
		printf("\n-------------------------------------------------------------");
		printf("\n\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the 1st number : ");
				scanf("%lf",&a);
				printf("Enter the 2nd number : ");
				scanf("%lf",&b);
				printf("%.15g + %.15g = %.15g\n",a,b,a+b);
				break;
			case 2: printf("Enter the 1st number : ");
				scanf("%lf",&a);
				printf("Enter the 2nd number : ");
				scanf("%lf",&b);
				printf("%.15g - %.15g = %.15g\n",a,b,a-b);
				break;
			case 3: printf("Enter the 1st number : ");
				scanf("%lf",&a);
				printf("Enter the 2nd number : ");
				scanf("%lf",&b);
				printf("%.15g * %.15g = %.15g\n",a,b,a*b);
				break;
			case 4: printf("Enter the 1st number : ");
				scanf("%lf",&a);
				printf("Enter the 2nd number : ");
				scanf("%lf",&b);
				if(b==0)
				{
					printf("Can't divide by zero\n");
				}
				else
				{
					printf("%.15g / %.15g = %.15g\n",a,b,a/b);
				}
				break;
			case 5: printf("Enter the 1st number : ");
				scanf("%lf",&a);
				printf("Enter the 2nd number : ");
				scanf("%lf",&b);
				if(a==(int)a && b==(int)b)
				{
					if(b==0)
					{
						printf("Can't divide by zero\n");
					}
					else
					{
						printf("%d %% %d = %d\n",(int)a,(int)b,((int)a)%((int)b));
					}
				}
				else
				{
					printf("Can't find Remainder for Non-Integers Values\n");
				}
				break;
			case 6: printf("Enter the 1st number : ");
				scanf("%lf",&a);
				printf("Enter the 2nd number : ");
				scanf("%lf",&b);
				if(a==(int)a && b==(int)b)
				{
					if(b==0)
					{
						printf("Can't divide by zero\n");
					}
					else
					{
						printf("%d // %d = %d\n",(int)a,(int)b,(int)(a/b));
					}
				}
				else
				{
					printf("Can't find Quotient for Non-Integers Values\n");
				}
				break;
			case 7: printf("Enter a number : ");
				scanf("%lf",&a);
				printf("Enter the Exponent : ");
				scanf("%lf",&b);
				printf("%.15g ^ %.15g = %.15g\n",a,b,pow(a,b));
				break;
			case 8: printf("Enter a number : ");
				scanf("%lf",&a);
				printf("Enter the Nth-Root : ");
				scanf("%lf",&b);
				printf("%.15g-th Root of %.15g = %.15g\n",b,a,pow(a,(1/b)));
				break;
			case 9: printf("Exiting...\n\n");
				exit(0);
			default: printf("Invalid Choice, Select Again.\n");
				 break;
		}
	}
	return 0;
}
