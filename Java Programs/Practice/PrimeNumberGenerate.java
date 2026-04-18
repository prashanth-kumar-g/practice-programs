import java.util.Scanner;

public class PrimeNumberGenerate
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter a number : ");
		int n = sc.nextInt();

		System.out.print("\n The prime numbers are :  "); 

		for(int i = 2; i <= n; i++)
		{
			boolean flag = true;

			for(int j = 2; j * j <= i; j++)
			{
				if(i % j == 0)
				{
					flag = false;
					break;
				}
			}

			if(flag)
			{
				System.out.print(i + "  ");
			}
		}

		System.out.println();
		
		sc.close();
	}
}