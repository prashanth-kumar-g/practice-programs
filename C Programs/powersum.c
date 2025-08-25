#include<stdio.h>
#include<math.h>
int main()
{
	double n,e,i,sum=0;
	printf("\nEnter the limit : ");
	scanf("%lf",&n);
	printf("Enter the exponent : ");
	scanf("%lf",&e);
	printf("\n");
	for(i=1;i<n;i++)
	{
		printf("%.15g + ",pow(i,e));
		sum=sum+pow(i,e);
	}
	printf("%.15g = %.15g\n\n",pow(i,e),sum+pow(i,e));
	return 0;
}
