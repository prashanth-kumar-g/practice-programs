#include<stdio.h>
#include<time.h>

double factorialUsingIteration(int n)
{
	double fact = 1;

	for(int i = 1; i <= n; i++)
	{
		fact = fact * i;
	}

	return fact;
}

double factorialUsingRecursion(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * factorialUsingRecursion(n - 1);
	}
}

int main()
{
	int n;
	double fact, cpu_time_used;
	clock_t start, end;

	printf("\n Enter a number : ");
	scanf("%d", &n);

	start = clock();
	fact = factorialUsingIteration(n);
	end = clock();
	cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;
	printf("\n Factorial of %d using Iteration is : %.0lf", n, fact);
	printf("\n Time Taken : %lf micro-seconds\n", cpu_time_used * 1000000.0);

	start = clock();
	fact = factorialUsingRecursion(n);
	end = clock();
	cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;
	printf("\n Factorial of %d using Recursion is : %.0lf", n, fact);
	printf("\n Time Taken : %lf micro-seconds\n\n", cpu_time_used * 1000000.0);

	return 0;
}
