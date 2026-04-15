import java.util.*;

public class ArmstrongNumberCheck
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("\n Enter a number : ");
		int n = sc.nextInt();
		
		int m = n;
		int totalDigits = 0;
		
		while(m != 0)		// (or) totalDigits = (int)Math.log10(n) + 1;
		{
			totalDigits++;
			m = m / 10;
		}
		
		int p = n;
		int num = 0;
		
		while(p != 0)
		{
			int rem = p % 10;
			
			int powResult = 1;
			for(int i = 0; i < totalDigits; i++)	// (or) powResult = (int)Math.pow(p, totalDigits);
			{
				powResult = powResult * rem;
			}
			num = num + powResult;
			
			p = p / 10;
		}
		
		if(num == n)
		{
			System.out.println("\n " + n + " is a Armstrong number");
		}
		else
		{
			System.out.println("\n " + n + " is not aArmstrong number");
		}
		
		sc.close();
	}
}