import java.util.Scanner;

public class IPA3a
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		int[] arr = new int[5];

		for(int i = 0; i < 5; i++)
		{
			arr[i] = sc.nextInt();
		}

		int oddSum = 0;

		for(int i = 0; i < 5; i++)
		{
			if(arr[i] % 2 != 0)
			{
				oddSum = oddSum + arr[i];
			}
		}

		if(oddSum > 8 && oddSum < 50)
		{
			System.out.print("Sum of odd numbers:" + oddSum);
		}
		else
		{
			System.out.print("NA");
		}

		sc.close();
	}
}