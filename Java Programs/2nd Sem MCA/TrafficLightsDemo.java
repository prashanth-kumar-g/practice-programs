class Buffer
{
	private boolean isRedTurn = true;
	private boolean isYellowTurn = false;
	private boolean isGreenTurn = false;

	synchronized public void printRed()
	{
		while(!isRedTurn)
		{
			try
			{
				wait();
			}
			catch(InterruptedException e)
			{
				System.out.println(e);
			}
		}

 		System.out.println("\n Red Light (T1) -> Stop");
		isRedTurn = false;
		isYellowTurn = true;
		notify();
	}

	synchronized public void printYellow()
	{
		while(!isYellowTurn)
		{
			try
			{
				wait();
			}
			catch(InterruptedException e)
			{
				System.out.println(e);
			}
		}

 		System.out.println("\n Yellow Light (T2) -> Be Ready");
		isYellowTurn = false;
		isGreenTurn = true;
		notify();
	}

	synchronized public void printGreen()
	{
		while(!isGreenTurn)
		{
			try
			{
				wait();
			}
			catch(InterruptedException e)
			{
				System.out.println(e);
			}
		}

 		System.out.println("\n Green Light (T3) -> Start \n");
		isGreenTurn = false;
		isRedTurn = true;
		notify();
	}
}

class Red extends Thread
{
	private Buffer buffer;
	private int max;

	Red(Buffer buffer, int max)
	{
		this.buffer = buffer;
		this.max = max;
	}

	public void run()
	{
		for(int i = 1; i <= max; i++)
		{
			buffer.printRed();

			try
			{
				sleep(1000);
			}
			catch(InterruptedException e)
			{
				System.out.println(e);
			}
		}
	}
}

class Yellow extends Thread
{
	private Buffer buffer;
	private int max;

	Yellow(Buffer buffer, int max)
	{
		this.buffer = buffer;
		this.max = max;
	}

	public void run()
	{
		for(int i = 1; i <= max; i++)
		{
			buffer.printYellow();

			try
			{
				sleep(1000);
			}
			catch(InterruptedException e)
			{
				System.out.println(e);
			}
		}
	}
}

class Green extends Thread
{
	private Buffer buffer;
	private int max;

	Green(Buffer buffer, int max)
	{
		this.buffer = buffer;
		this.max = max;
	}

	public void run()
	{
		for(int i = 1; i <= max; i++)
		{
			buffer.printGreen();

			try
			{
				sleep(1000);
			}
			catch(InterruptedException e)
			{
				System.out.println(e);
			}
		}
	}
}

public class TrafficLightsDemo
{
	public static void main(String [] args)
	{
		Buffer buffer = new Buffer();


		if(args.length < 1)
		{
			System.out.println("\n A command-line argument is required to give max limit \n");
			return;
		}


		int max = Integer.parseInt(args[0]);


		Red T1 = new Red(buffer, max);

		Yellow T2 = new Yellow(buffer, max);

		Green T3 = new Green(buffer, max);


		T1.start();

		T2.start();

		T3.start();
	}
}
