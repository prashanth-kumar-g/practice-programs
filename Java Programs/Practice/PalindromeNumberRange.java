import java.util.Scanner;

public class PalindromeNumberRange
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter the range (m & n) : ");
		int m = sc.nextInt();
		int n = sc.nextInt();
		
		System.out.print("The palindrome numbers are : ");

		int num = m;

		while(num <= n)
		{
			int temp = num;
			
			result = 0;
			
			while(temp != 0)
			{
				int rem = result % 10;
				result = result * 10 + rem;
				result = result / 10;
			}
			
			if(result == num)
			{
				System.out.print(num + " ");
			}
			
			num++;
		}
		
		System.out.println();
		
		sc.close();
	}
}	