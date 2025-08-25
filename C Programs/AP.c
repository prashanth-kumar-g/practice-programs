#include<stdio.h>
int main()
{
	int a,d,n,i,j,sum=0;
	printf("\nEnter the first term : ");
	scanf("%d",&a);
	printf("Enter the common difference ");
	scanf("%d",&d);
	printf("Enter the number of terms : ");
	scanf("%d",&n);
	printf("\n");
	j=a;
	sum=j;
	printf("%d + ",j);
	for(i=2;i<n;i++)
	{
		j=j+d;
		printf("%d + ",j);
		sum=sum+j;
	}
	printf("%d = %d\n\n",j+d,sum+(j+d));
	return 0;
}
