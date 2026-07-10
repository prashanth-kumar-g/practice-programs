import java.util.*;

public class IPAQPV
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int[] numbers = new int[5];
		
		for (int i = 0; i < 5; i++)
		{
			numbers[i] = sc.nextInt();
		}
		
		for (int i = 0; i < 5; i++)
		{
			long factorial = 1;
			
			for (int j = 1; j <= numbers[i]; j++)
			{
				factorial = factorial * j;
			}
			
			System.out.println(factorial);
		}
		
		sc.close();
	}
}
