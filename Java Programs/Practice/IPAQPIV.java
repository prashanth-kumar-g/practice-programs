import java.util.*;

public class IPAQPIV
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		String input = sc.nextLine();
		
		char minChar = input.charAt(0);
		
		for (int i = 1; i < input.length(); i++)
		{
			if (input.charAt(i) < minChar)
			{
				minChar = input.charAt(i);
			}
		}
		
		System.out.println(minChar);
		
		sc.close();
	}
}
