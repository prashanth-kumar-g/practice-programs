import java.util.Scanner;

public class PalindromeNumberGenerate
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter a number : ");
		int n = sc.nextInt();
		
		System.out.print("The palindrome numbers are : ");

		int num = 0;
		int count = 0;

		while(count != 0)
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
				count++;
			}
			
			num++;
		}
		
		System.out.println();
		
		sc.close();
	}
}	