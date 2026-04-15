import java.util.Scanner;

public class PrimeGenerateRange
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter the  range (m & n) : ");
		int m = sc.nextInt();
		int n = sc.nextInt();

		if(m < 0) return;

		if(m == 0 || m == 1)
		{
			m = 2;
		}

		System.out.print("\n The prime numbers are :  "); 

		for(int i = m; i <= n; i++)
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