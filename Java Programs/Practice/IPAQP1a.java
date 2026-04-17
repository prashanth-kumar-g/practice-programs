import java.util.Scanner;

public class IPAQP1a
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int[] arr = new int[5];
		
		for(int i = 0; i < 5; i++)
		{
			arr[i] = sc.nextInt();
		}
		
		int l1 = sc.nextInt();
		int l2 = sc.nextInt();

		int sum = 0, count = 0;

		for(int i = 0; i < 5; i++)
		{
			if(arr[i] > l1 && arr[i] < l2)
			{
				sum = sum + arr[i];
				count++;
			}
		}

		if(count > 0)
		{
			int avg = sum / count;
			System.out.print(avg);
		}
		else
		{
			System.out.print(0);
		}

		sc.close();		
	}
}