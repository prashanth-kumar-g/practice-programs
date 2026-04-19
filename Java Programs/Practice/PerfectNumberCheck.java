// Perfect Number: A number equal to the sum of its proper divisors 
// excluding itself (e.g., 6 = 1 + 2 + 3, 28 = 1 + 2 + 4 + 7 + 14)

import java.util.*;

public class PerfectNumberCheck
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter a number : ");
		int n = sc.nextInt();
		
		List<Integer> factors = new ArrayList<>();
		
		factors.add(1);

		for(int i = 2; i * i <= n; i++)
		{
			int temp = n;
			
			if(n % i == 0)
			{
				int quot = temp / i;
				
				factors.add(i);
				
				factors.add(quot);
			}
		}
		
		int sum = 0;

		for(int f : factors)
		{
			sum = sum + f;
		}

		if( !(sum == n) || n == 1)
		{
			System.out.println("\n " + n + " is not a perfect number");
		}
		else
		{
			System.out.println("\n " + n + " is a perfect number");
		}
		
		sc.close();
	}
}