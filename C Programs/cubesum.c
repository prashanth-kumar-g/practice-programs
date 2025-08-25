#include<stdio.h>
int main()
{
	int n,i,sum=0;
	printf("\nEnter the limit : ");
	scanf("%d",&n);
	printf("\n");
	for(i=1;i<n;i++)
	{
		printf("%d + ",i*i*i);
		sum=sum+i*i*i;
	}
	printf("%d = %d\n\n",i*i*i,sum+i*i*i);
	return 0;
}
