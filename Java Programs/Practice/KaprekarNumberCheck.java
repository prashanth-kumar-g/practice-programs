// Kaprekar Number: A number whose square can be split into two parts whose sum is the
// original number (e.g., 45 → 45² = 2025 → 20 + 25 = 45, 297 → 297² = 88209 → 88 + 209 = 297)

import java.util.*;

public class KaprekarNumberCheck
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter a number : ");
		int n = sc.nextInt();

		int squaredNum = n * n;
		
		int totalDigits = (int)Math.log10(n) + 1;

		int partNum1 = 0, partNum2 = 0;
		
		int temp = squaredNum, count = 0, i = 1, j = 1;
		
		while(temp != 0)
		{
			int rem = temp % 10;
			
			if(count < totalDigits)
			{
				partNum2 = partNum2 + rem * i;
				count++;
				i *= 10;
			}
			else
			{
				partNum1 = partNum1 + rem * j;
				j *= 10;
			}
			
			temp = temp / 10;
		}

		if( (partNum1 + partNum2) == n )
		{
			System.out.println("\n " + n + " is a kaprekar number" + ", since " + n + "² = " + squaredNum + " → " + partNum1 + " + " + partNum2 + " = " + n);
		}
		else
		{
			System.out.println("\n " + n + " is not a kaprekar number" + ", since " + n + "² = " + squaredNum + " → " + partNum1 + " + " + partNum2 + " = " + (partNum1 + partNum2));
		}
		
		sc.close();
	}
}