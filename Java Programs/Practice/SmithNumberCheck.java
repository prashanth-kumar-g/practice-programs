// Smith Number: A composite number whose sum of digits is equal to the sum of digits
// of its prime factors (e.g.1., 22 → 2+2 = 4 & 22 = 2 * 11 → 2 + (1 + 1) = 4)
// (e.g.2., 27 → 2+7 = 9 & 27 = 3 * 3 * 3 → 3 + 3 + 3 = 9)

import java.util.*;

public class SmithNumberCheck
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter a number : ");
		int n = sc.nextInt();
		
		int temp = n;
		
		int sumofDigits = 0;
		
		while(temp != 0)
		{
			int rem = temp % 10;
			sumofDigits = sumofDigits + rem;
			temp = temp / 10;
		}

		List<Integer>  primeFactors = new ArrayList<>();
		
		temp = n;
		
		while(temp != 1)
		{
			for(int i = 2; i <= temp; i++)
			{
				if(temp % i == 0)
				{
					primeFactors.add(i);
					temp = temp / i;
					break;
				}
			}
		}
		
		int sumOfDigitsOfPrimeFactors = 0;
		
		for(int p : primeFactors)
		{
			int totalDigits = (int)Math.log10(p) + 1;
			
			if(totalDigits == 1)
			{
				sumOfDigitsOfPrimeFactors = sumOfDigitsOfPrimeFactors + p;
			}
			else
			{
				temp = p;
				
				while(temp != 0)
				{
					int rem = temp % 10;
					sumOfDigitsOfPrimeFactors = sumOfDigitsOfPrimeFactors + rem;
					temp = temp / 10;
				}
			}
		}

		if( (sumofDigits != sumOfDigitsOfPrimeFactors) || (primeFactors.size() == 1) )
		{
			System.out.println("\n " + n + " is not a smith number");
		}
		else
		{
			System.out.println("\n " + n + " is a smith number");
		}
		
		sc.close();
	}
}