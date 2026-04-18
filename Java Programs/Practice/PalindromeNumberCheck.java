import java.util.Scanner;

public class PalindromeNumberCheck
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter a number : ");
		int n = sc.nextInt();

		int m = n;
		int rev = 0;

		while(m != 0)
		{
			int rem = m % 10;
			rev = rev * 10 + rem;
			m = m / 10;
		}

		if(n == rev)
		{
			System.out.println("\n " + n + " is a palindrome");
		}
		else
		{
			System.out.println("\n " + n + " is not a palindrome");
		}
		
		sc.close();
	}
}	