// Harshad/Niven Number: A number divisible by the sum of its digits (e.g., 18 → 1+8=9, 18/9=2)

import java.util.*;

public class HarshadNumberCheck
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter a number : ");
		int n = sc.nextInt();
		
		int temp = n;
		int sumOfDigits = 0;

		while(temp != 0)
		{
			int rem = temp % 10;
			sumOfDigits = sumOfDigits + rem;
			temp = temp / 10;
		}

		if(n % sumOfDigits == 0)
		{
			System.out.println("\n " + n + " is a harshad number");
		}
		else
		{
			System.out.println("\n " + n + " is not a harshad number");
		}
		
		sc.close();
	}
}