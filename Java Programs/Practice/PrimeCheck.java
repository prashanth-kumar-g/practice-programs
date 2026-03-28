import java.util.Scanner;

public class PrimeCheck
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter a number : ");
		int n = sc.nextInt();

		boolean flag = true;
		for(int i = 2; i * i <= n; i++)
		{
			if(n % i == 0)
			{
				flag = false;
				break;
			}		
		}

		if(flag)
		{
			System.out.println("\n " + n + " is a prime number");
		}
		else
		{
			System.out.println("\n " + n + " is not a prime number");
		}
	}
}		