#include<stdio.h>
int main()
{
	int n;
	printf("\nEnter the limit : ");
	scanf("%d",&n);
	printf("\nThe prime numbers are : ");
	for(int i=2;i<=n;i++)
	{
		int sig=0;
		for(int j=2;j*j<i;j++)
		{
			if(i%j==0)
			{
				sig=1;
				break;
			}
		}
		if(sig==0)
		{
			printf("%d ",i);
		}
	}
	printf("\n\n");
	return 0;
}
