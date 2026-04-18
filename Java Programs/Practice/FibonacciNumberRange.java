import java.util.*;

public class FibonacciNumberRange
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("\n Enter the range (m & n) : ");
		int m = sc.nextInt();
		int n = sc.nextInt();
		
		int f1 = 0, f2 = 1;
		
		while(f1 < m)
		{
			int fn = f1 + f2;
			f1= f2;
			f2 = fn;
		}
		
		System.out.print("\n The fibonacci series is : ");
		
		while(f1 <= n)
		{
			System.out.print(f1 + " ");
			
			int fn = f1 + f2;
			f1 = f2;
			f2 = fn;
		}
		
		System.out.println();
		
		sc.close();
	}
}