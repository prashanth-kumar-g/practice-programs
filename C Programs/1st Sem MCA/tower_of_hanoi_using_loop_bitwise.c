// tower of hanoi using loop

#include<stdio.h>

int countTrailingZero(int n)
{
	int count = 0;
	while((n & 1)==0 && n!=0)
	{
		count++;
		n=n>>1;
	}
	return count;
}

void towerOfHanoi(int n, char A, char B, char C)
{
	int totalMoves = (1 << n) - 1;

	char rods[3] = {A,B,C};

	if(n%2==0)
	{
		char temp = rods[1];
		rods[1] = rods[2];
		rods[2] = temp;
	}

	for(int i = 1; i <= totalMoves; i++)
	{
		int disk = countTrailingZero(i) + 1;
		int fromRod = (i & (i - 1)) % 3;
		int toRod = ((i | (i - 1)) + 1) % 3;
		printf("\n Move disk %d from rod %c to rod %c",disk,rods[fromRod],rods[toRod]);
	}
}

int main()
{
	int n;
	printf("\n-----------------------------------------------------------");
	printf("\n                TOWER OF HANOI USING LOOP                  ");
	printf("\n               ---------------------------                 ");
	printf("\n\n Enter the number of disk : ");
	scanf("%d",&n);
	towerOfHanoi(n,'A','B','C');
	printf("\n\n-----------------------------------------------------------\n\n");
	return 0;
}
