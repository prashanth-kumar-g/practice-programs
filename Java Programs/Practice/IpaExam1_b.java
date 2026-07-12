import java.util.*;

public class IpaExam1_b
{
	public static int CountWords(String str)
	{
		if (str == null || str.trim().isEmpty())
		{
			return 0;
		}
		
		String[] words = str.trim().split("\\s+");
		
		return words.length;
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		String str = sc.nextLine();
			
		int result = CountWords(str);
		
		System.out.println(result);
		
		sc.close();
	}
}
