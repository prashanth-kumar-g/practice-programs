#include<stdio.h>
int main()
{
	int n,i,sum=0;
	printf("\nEnter the limit : ");
	scanf("%d",&n);
	printf("\n");
	for(i=2;i<n;i=i+2)
	{
		printf("%d + ",i);
		sum=sum+i;
	}
	printf("%d = %d\n\n",i,sum+i);
	return 0;
}
