// Program to print floyd's triangle number pattern

#include<stdio.h>

int main()
{
	int n;
	printf("\n-----------------------------------------------------------");
	printf("\n              FLOYD'S TRIANGLE NUMBER PATTERN              ");
	printf("\n             ---------------------------------             ");
	printf("\n\nEnter the number of lines : ");
	scanf("%d",&n);
	printf("\n");
	int k=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf("%d ",k);
			k++;
		}
		printf("\n");
	}
	printf("-----------------------------------------------------------\n\n");
	return 0;
}

