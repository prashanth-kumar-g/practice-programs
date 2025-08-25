#include<stdio.h>
int main()
{
	int a,r,n,i,j,sum=0;
	printf("\nEnter the first term : ");
	scanf("%d",&a);
	printf("Enter the common ratio : ");
	scanf("%d",&r);
	printf("Enter the number of terms : ");
	scanf("%d",&n);
	printf("\n");
	j=a;
	sum=j;
	printf("%d + ",j);
	for(i=2;i<n;i++)
	{
		j=j*r;
		printf("%d + ",j);
		sum=sum+j;
	}
	printf("%d = %d\n\n",j*r,sum+(j*r));
	return 0;
}
