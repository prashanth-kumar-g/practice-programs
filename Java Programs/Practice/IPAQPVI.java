import java.util.*;

public class IPAQPVI
{
	public static boolean isPrime(int num)
	{
		if (num <= 1)
		{
			return false;
		}
		
		for (int i = 2; i * i <= num; i++)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
		
		return true;
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		int largest = Integer.MIN_VALUE;
		int secondLargest = Integer.MIN_VALUE;
		
		for (int i = 0; i < n; i++)
		{
			int current = sc.nextInt();
			
			if (isPrime(current))
			{
				if (current > largest)
				{
					secondLargest = largest;
					largest = current;
				}
				else if (current < largest && current > secondLargest)
				{
					secondLargest = current;
				}
			}
		}
		
		System.out.println(secondLargest);
		
		sc.close();
	}
}
