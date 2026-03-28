import java.util.Scanner ;

public class StarPattern
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter the number of lines : ");
		int n = sc.nextInt();

		System.out.println();

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				System.out.print(" * ");
			}

			System.out.println();
		}
	
		sc.close();
	}
}	