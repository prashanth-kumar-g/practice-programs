import java.util.*;

public class ArmstrongNumberRange
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("\n Enter the range (m & n) : ");
		int n = sc.nextInt();
		
		System.out.print("\n The Armstrong numbers are : ");
		
		long num = m;
		
		while(num <= n)
		{
			long temp = num;
			int totalDigits = (int)Math.log10(num) + 1;
			long result = 0;
			
			while(temp != 0)
			{
				int rem = (int)temp % 10;
				result = result + (int)Math.pow(rem, totalDigits);
				temp = temp / 10;
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