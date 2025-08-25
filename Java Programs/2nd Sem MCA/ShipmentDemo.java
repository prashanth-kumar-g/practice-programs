// Abstract base class

abstract class Box
{
	double length, breadth, height;

	// Default constructor
	Box()
	{
		length = breadth = height = 0;
	}

	// Constructor with dimensions
	Box(double l, double b, double h)
	{
		length = l;
		breadth = b;
		height = h;
	}

	// Constructor to clone object
	Box(Box ob)
	{
		length = ob.length;
		breadth = ob.breadth;
		height = ob.height;
	}

	// Constructor for cube
	Box(double len)
	{
		length = breadth = height = len;
	}

	// Abstract method for volume
	abstract double volume();
}

// First level subclass
class BoxWeight extends Box
{
	double weight;

	// Default constructor
	BoxWeight()
	{
		super();
		weight = 0;
	}

	// Constructor with all parameters
	BoxWeight(double l, double b, double h, double w)
	{
		super(l, b, h);
		weight = w;
	}

	// Clone constructor
	BoxWeight(BoxWeight ob)
	{
		super(ob);
		weight = ob.weight;
	}

	// Constructor for cube
	BoxWeight(double len, double w)
	{
		super(len);
		weight = w;
	}

	// Overriding volume method
	double volume()
	{
		return length * breadth * height;
	}
}

// Final class to prevent further inheritance
final class Shipment extends BoxWeight
{
	double cost;

	// Default constructor
	Shipment()
	{
		super();
		cost = 0;
	}

	// Constructor with all parameters
	Shipment(double l, double b, double h, double w, double c)
	{
		super(l, b, h, w);
		cost = c;
	}

	// Clone constructor
	Shipment(Shipment ob)
	{
		super(ob);
		cost = ob.cost;
	}

	// Constructor for cube
	Shipment(double len, double w, double c)
	{
		super(len, w);
		cost = c;
	}

	// Overriding volume method
	double volume()
	{
		return length * breadth * height;
	}

	// Final method - can't be overridden
	final void displayCost()
	{
		System.out.println("  Shipping cost is: $" + cost);
	}
}

// Demo class
public class ShipmentDemo
{
	public static void main(String args[])
	{
		double vol;

		Shipment shipment1 = new Shipment(5, 12, 13, 3.0, 12.33);
		System.out.println("Shipment 1");
		vol = shipment1.volume();
		System.out.println("  Volume is: " + vol);
		System.out.println("  Weight is: " + shipment1.weight);
		shipment1.displayCost();

		System.out.println();

		Shipment shipment2 = new Shipment(3, 4, 5, 0.53, 1.64);
		System.out.println("Shipment 2");
		vol = shipment2.volume();
		System.out.println("  Volume is: " + vol);
		System.out.println("  Weight is: " + shipment2.weight);
		shipment2.displayCost();
	}
}
