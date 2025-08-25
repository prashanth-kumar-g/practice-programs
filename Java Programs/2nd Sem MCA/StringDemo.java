import java.util.Scanner;

class Box
{
	double length, breadth, height;

	Box(double l, double b, double h)
	{
		length = l;
		breadth = b;
		height = h;
	}

	public String toString()
	{
		return "The dimensions are " + length + " by " + breadth + " by " + height + ".";
	}
}

public class StringDemo
{
	// Method using varargs
	static void printWords(String... words)
	{
		System.out.println("\nWords passed using varargs:");

		for (String word : words)
		{
			System.out.println("  " + word);
		}
	}

	public static void main(String args[])
	{
		// Box and toString
		Box b = new Box(10, 12, 14);
		System.out.println("Box object 'b' is: " + b);

		// Converted to string
		String s = "The box b is " + b;
		System.out.println("\nString 's' after conactenation with 'b' is: " + s);

		// String manipulation
		String s2 = "Face the failure until the failure fails to face you";
		System.out.println("\nString 's2' is: " + s2);
		int start = 16, end = 40;
		char buf[] = new char[end - start];
		s2.getChars(start, end, buf, 0);
		System.out.println("Extracted substring of 's2' from index 16 to 40 is: " + new String(buf));

		// Command-line arguments
		System.out.println("\nNumber of command-line arguments is: " + args.length);
		for (int i = 0; i < args.length; i++)
		{
			System.out.println("  Argument " + (i + 1) + ": " + args[i]);
		}

		// Varargs method
		printWords("Java", "String", "Varargs", "Method");

		// Scanner input
		Scanner sc = new Scanner(System.in);
		System.out.print("\nEnter a sentence: ");
		String input = sc.nextLine();
		System.out.println("You entered: " + input);
		sc.close();
	}
}
