import java.util.*;

public class PerfectSquareCheck
{
	static boolean LibraryFunctionMethod(int n)
	{
		if(n < 0) return false;

		int root = (int)Math.sqrt(n);

		if(root * root == n)
		{
			return true;
		}

		return false;
	}

	static boolean BruteForceMethod(int n)
	{
		if(n < 0) return false;

		for(int i = 1; i * i <= n; i++)
		{
			if(i * i == n)
			{
				return true;
			}
		}

		return false;
	}

	static boolean BinarySearchMethod(int n)
	{
		if(n < 0) return false;

		int low = 1, high = n;

		while(low <= high)
		{
			int mid = (low + high) / 2;
			
			int square = mid * mid;

			if(square == n)
			{
				return true;
			}
			else if(square < n)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}

		return false;
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int n;
		int ch;

		while(true)
		{
			System.out.println("\n-----------------------------------------------------------------------");
			System.out.println("                     PERFECT SQUARE CHECKER                              ");
			System.out.println("                    ------------------------                             ");
			System.out.println(" 1) Using Library Function        2) Using Brute Force Method            ");
			System.out.println(" 3) Using Binary Search Method    4) Exit                                ");
			System.out.println("-------------------------------------------------------------------------");
			System.out.print("\n Enter your choice : ");
			ch = sc.nextInt();

			switch(ch)
			{
				case 1: System.out.print("\n Enter a number : ");
						n = sc.nextInt();
						
						if(LibraryFunctionMethod(n))
						{
							System.out.println("\n " + n + " is a perfect square using Library Function Method");
						}
						else
						{
							System.out.println("\n " + n + " is not a perfect square using Library Function Method");
						}
						
						break;

				case 2: System.out.print("\n Enter a number : ");
						n = sc.nextInt();
						
						if(BruteForceMethod(n))
						{
							System.out.println("\n " + n + " is a perfect square using Brute Force Method");
						}
						else
						{
							System.out.println("\n " + n + " is not a perfect square using Brute Force Method");
						}
						
						break;

				case 3: System.out.print("\n Enter a number : ");
						n = sc.nextInt();
						
						if(BinarySearchMethod(n))
						{
							System.out.println("\n " + n + " is a perfect square using Binary Search Method");
						}
						else
						{
							System.out.println("\n " + n + " is not a perfect square using Binary Search Method");
						}
						
						break;

				case 4: System.out.println("\n Exiting...");
						System.exit(0);

				default: System.out.println("\n Invalid Choice, Select Again.");
			}
		}
	}
}