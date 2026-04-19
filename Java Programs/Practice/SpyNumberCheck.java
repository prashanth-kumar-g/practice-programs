// Spy Number: A number whose sum of digits is equal to the 
// product of its digits (e.g., 1124 → 1+1+2+4 = 1×1×2×4 = 8)

import java.util.*;

public class SpyNumberCheck
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter a number : ");
		int n = sc.nextInt();

		int sumOfDigits = 0;
		int productOfDigits = 1;
		
		int temp = n;
		
		while(temp != 0)
		{
			int rem = temp % 10;
			sumOfDigits = sumOfDigits + rem;
			productOfDigits = productOfDigits * rem;
			temp = temp / 10;
		}

		if(sumOfDigits == productOfDigits)
		{
			System.out.println("\n " + n + " is a spy number");
		}
		else
		{
			System.out.println("\n " + n + " is not a spy number");
		}
		
		sc.close();
	}
}