// Demonstrate class fundamentals in Java

class Box
{
	double length, breadth, height;

	// Constructor using this keyword
	Box(double length, double breadth, double height)
	{
		this.length = length;
		this.breadth = breadth;
		this.height = height;
	}

	// Method to calculate and return volume
	double volume()
	{
		return length * breadth * height;
	}

	// Finalize method called before object is destroyed
	@Override
	protected void finalize()
	{
		System.out.println("Box object is being destroyed.");
	}
}

public class BoxDemo
{
	public static void main(String[] args)
	{
		// Create objects of Box
		Box myBox1 = new Box(10, 20, 15);
		Box myBox2 = new Box(3, 6, 9);

		double vol;
		// Get volume of first box
		vol = myBox1.volume();
		System.out.println("Volume of myBox1 is: " + vol);

		// Get volume of second box
		vol = myBox2.volume();
		System.out.println("Volume of myBox2 is: " + vol + "\n");

		// Hint for garbage collector (not guaranteed)
		myBox1 = null;
		myBox2 = null;
		// Request garbage collection
		System.gc(); // This may call finalize(), but not guaranteed immediately
	}
}
