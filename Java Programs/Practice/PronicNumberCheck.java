// Pronic Number: A number that is the product of two
// consecutive integers (e.g., 6 = 2 * 3, 110 = 10 * 11)

// consider 'n' as a number, then x is a pronic
// number, if n = x * (x + 1)

// To get, the value of two consective integers, solve
// for 'x' in equation n = x * (x + 1) → x^2 + x - n = 0

// if ax^2 + bx + c = 0, then x = (-b ± √(b^2 - 4ac)) / 2a
// so for x^2 + x - n = 0, n = (-1 ± √(1 + 4n)) / 2

import java.util.*;

public class PronicNumberCheck
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter a number : ");
		int n = sc.nextInt();

		int d = (int)Math.sqrt(1 + 4 * n)
		
		int r1 = (-1 + d) / 2;
		int r2 = Math.abs((-1 - d) / 2);

		if(r1 * r2 == n)
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