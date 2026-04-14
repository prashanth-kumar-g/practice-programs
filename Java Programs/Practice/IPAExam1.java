import java.util.*;

public class IPAExam1
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		int count = 0;
		
		int temp = n;
		
		while(temp != 0)
		{
			int digit = temp % 10;
			
			if(digit % 2 != 0)
			{
				count++;
			}
			
			temp = temp / 10;
		}
		
		/*
		String num = String.valueOf(n);
		
		for(int i = 0; i < num.length(); i++)
		{
			char digit = num.charAt(i);
			
			if( ((int)(digit - '0')) % 2 != 0 )
			{
				count++;
			}
		}
		*/
		
		if(count >= 3)
		{
			System.out.println("TRUE");
		}
		else
		{
			System.out.println("FALSE");
		}
		
		sc.close();
	}
}