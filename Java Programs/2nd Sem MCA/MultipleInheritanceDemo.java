interface Car
{
	default void drive()
	{
		System.out.println("\n Driving on road...");
	}
}

interface Airplane
{
	default void fly()
	{
		System.out.println("\n Flying in the sky...");
	}
}

class FlyingCar implements Car, Airplane
{
	public void transform()
	{
		System.out.println("\n Switching between driving and flying modes... \n");
	}
}

public class MultipleInheritanceDemo
{
	public static void main(String [] args)
	{
		FlyingCar obj = new FlyingCar();

		obj.drive();

		obj.fly();

		obj.transform();
	}
}

