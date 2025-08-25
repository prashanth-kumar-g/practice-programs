// Program to solve tower of hanoi

#include<stdio.h>

void towerOfHanoi(int n, char A, char B, char C)
{
	if(n<=0)
	{
		printf("\n No disk to move");
	}
	else if(n==1)
	{
		printf("\n  Move disk %d from rod %c to rod %c",n,A,C);
	}
	else
	{
		towerOfHanoi(n-1,A,C,B);
		printf("\n  Move disk %d from rod %c to rod %c",n,A,C);
		towerOfHanoi(n-1,B,A,C);
	}
}

int main()
{
	int n;
	printf("\n--------------------------------------");
	printf("\n            TOWER OF HANOI            ");
	printf("\n           ----------------           ");
	printf("\n\n Enter the number of disks : ");
	scanf("%d",&n);
	towerOfHanoi(n,'A','B','C');
	printf("\n\n--------------------------------------\n\n");
	return 0;
}
