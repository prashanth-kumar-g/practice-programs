import java.util.*;

public class Example
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		List<Integer> factors= new ArrayList<>();

		factors.add(1);

		int temp = n;
		for(int i = 2; i * i <= n; i++)
		{
			if(temp % i == 0)
			{
				factors.add(i);
				int qout = temp / i;
				factors.add(qout);
			}
		}

		int sumOfDivisors = 0;
		for(int p : factors)
		{
			sumOfDivisors = sumOfDivisors + p;
		}

		if(n == sumOfDivisors)
		{
			System.out.println("\n" + n + " is a Special Number");
		}
		else
		{
			System.out.println("\n" + n + " is not a Special Number");
		}

		sc.close();
	}
}