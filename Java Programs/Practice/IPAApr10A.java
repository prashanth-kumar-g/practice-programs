import java.util.*;

public class IPAApr10A 
{
    public static void main(String[] args) 
	{
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();

        int[] freq = new int[256];
        StringBuilder result = new StringBuilder();
        boolean hasDuplicate = false;

        for (int i = 0; i < input.length(); i++) 
		{
            char ch = input.charAt(i);

            if (Character.isLetter(ch)) 
			{
                freq[ch]++;

                if (freq[ch] == 2) 
				{
                    result.append('?');
                    hasDuplicate = true;
                } 
				else 
				{
                    result.append(ch);
                }
            } 
			else 
			{
                result.append(ch);
            }
        }

        if (hasDuplicate) 
		{
            System.out.print(result.toString());
        } 
		else 
		{
            System.out.print("No duplicates present in the given string");
        }

        sc.close();
    }
}