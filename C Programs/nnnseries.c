#include<stdio.h>
#include<math.h>
int main()
{
	double m,n,l,i,j,sum=0;
	printf("\nseries : m + mm + mmm + mmmm + mmmmm + ......\n");
	printf("\nEnter a number (0-9) : ");
	scanf("%lf",&m);
	printf("Enter the number of terms : ");
	scanf("%lf",&n);
	printf("\n");
	j=m;
	sum=j;
	printf("%.15g + ",j);
	for(i=2;i<n;i++)
	{
		j=j+m*pow(10,i-1);
		printf("%.15g + ",j);
		sum=sum+j;
	}
	printf("%.15g = %.15g\n\n",j+m*pow(10,i-1),sum+(j+m*pow(10,i-1)));
	return 0;
}
