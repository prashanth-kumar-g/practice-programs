import java.util.Scanner;

public class IPAQP2a
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		int num = sc.nextInt();

		int digitSum = 0;

		while(num != 0)
		{	
			int rem = num % 10;
			digitSum = digitSum + rem;
			num = num / 10;
		}

		if(digitSum % 3 == 0)
		{
			System.out.print("TRUE");
		}
		else
		{
			System.out.print("FALSE");
		}

		sc.close();
	}
}