import java.util.*;

public class FibonacciNumberGenerate
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("\n Enter the number of terms : ");
		int n = sc.nextInt();
		
		System.out.print("\n The fibonacci series is : ");
		
		int f1 = 0, f2 = 1;
		
		for(int i = 0; i < n; i++)
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