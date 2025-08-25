#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int GcdUsingEuclidMethod(int m, int n)
{
	int r;

	while(n!=0)
	{
		r = m % n;
		m = n;
		n = r;
	}

	return m;
}

int GcdUsingConsecutiveIntegerMethod(int m, int n)
{
	if(m==0) return n;
	if(n==0) return m;

	int min = (m<n)?m:n;

	for(int i = min; i >= 1; i--)
	{
		if( (m % i) == 0 && (n % i == 0) )
		{
			return i;
		}
	}

	return 1;
}

int FindFactors(int q, int Factors[])
{
	int count = 0;

	while(q != 1)
	{
		for(int d = 2; d <= q; d++)
		{
			if(q % d == 0)
			{
				Factors[count++] = d;
				q = q / d;
				break;
			}
		}
	}

	return count;
}

int GcdUsingFactorisationMethod(int m, int n)
{
	if(m==0) return n;
	if(n==0) return m;

	int FactorsM[100], FactorsN[100];
	int CountM = FindFactors(m,FactorsM);
	int CountN = FindFactors(n,FactorsN);
	int used[100] = {0}, gcd = 1;

	for(int i = 0; i < CountM; i++)
	{
		for(int j = 0; j < CountN; j++)
		{
			if(!used[j] && FactorsM[i] == FactorsN[j])
			{
				gcd = gcd * FactorsM[i];
				used[j] = 1;
				break;
			}
		}
	}

	return gcd;
}

int main()
{
	int m,n,ch,gcd;
	clock_t start, end;
	double cpu_time_used;

	while(1)
	{
		printf("\n-----------------------------------------------------------------------");
		printf("\n                     FIND GREATEST COMMON DIVISOR                      ");
		printf("\n                    ------------------------------                     ");
		printf("\n 1) Using Euclid's Method       2) Using Consecutive_Integer Method    "); 
		printf("\n 3) Using Factorisation Method  4) Exit                                ");
		printf("\n-----------------------------------------------------------------------");
		printf("\n\n Enter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("\n Enter two numbers : ");
				scanf("%d %d", &m, &n);
				if(m<0) m = abs(m);
				if(n<0) n = abs(n);
				start = clock();
				gcd = GcdUsingEuclidMethod(m, n);
				end = clock();
				printf("\n GCD of %d and %d Using Euclid's Method is : %d\n", m, n, gcd);
				cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;
				printf("\n Time Taken : %lf seconds", cpu_time_used);
				printf("\n Time Taken : %lf milli-seconds", cpu_time_used * 1000.0);
				printf("\n Time Taken : %lf micro-seconds\n", cpu_time_used * 1000000.0);
				break;

			case 2: printf("\n Enter two numbers : ");
				scanf("%d %d", &m, &n);
				if(m<0) m = abs(m);
				if(n<0) n = abs(n);
				start = clock();
				gcd = GcdUsingConsecutiveIntegerMethod(m, n);
				end = clock();
				printf("\n GCD of %d and %d Using Consecutive-Integer Method is : %d\n", m, n, gcd);
				cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;
				printf("\n Time Taken : %lf seconds", cpu_time_used);
				printf("\n Time Taken : %lf milli-seconds", cpu_time_used * 1000.0);
				printf("\n Time Taken : %lf micro-seconds\n", cpu_time_used * 1000000.0);
				break;

			case 3: printf("\n Enter two numbers : ");
				scanf("%d %d", &m, &n);
				if(m<0) m = abs(m);
				if(n<0) n = abs(n);
				start = clock();
				gcd = GcdUsingFactorisationMethod(m, n);
				end = clock();
				printf("\n GCD of %d and %d Using Factorisation Method is : %d\n", m, n, gcd);
				cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;
				printf("\n Time Taken : %lf seconds", cpu_time_used);
				printf("\n Time Taken : %lf milli-seconds", cpu_time_used * 1000.0);
				printf("\n Time Taken : %lf micro-seconds\n", cpu_time_used * 1000000.0);
				break;

			case 4: printf("\n Exiting... \n\n");
				exit(0);

			default: printf("\n Invalid Choice, Select Again. \n");
				 break;
		}
	}

	return 0;
}
