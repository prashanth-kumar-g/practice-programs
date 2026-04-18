import java.util.*;

public class FibonacciNumberCheck
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("\n Enter the number of terms : ");
		int n = sc.nextInt();
		
		int f1 = 0, f2 = 1;
		boolean flag = false;
		
		while(f1 <= n)
		{
			if(f1 == n)
			{
				flag = true;
			}
			
			int fn = f1 + f2;
			f1 = f2;
			f2 = fn;
		}
		
		if(flag)
		{
			System.out.println(n + " is a fibonacci number");
		}
		else
		{
			System.out.println(n + " is not a fibonacci number");
		}
		
		
		sc.close();
	}
}