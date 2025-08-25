class Buffer
{
	private boolean isOddTurn = true;

	synchronized public void printOdd(int value)
	{
		while(!isOddTurn)
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

 		System.out.println("\n Odd (T1) : " + value);
		isOddTurn = false;
		notify();
	}

	synchronized public void printEven(int value)
	{
		while(isOddTurn)
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

 		System.out.println("\n Even (T2) : " + value + "\n");
		isOddTurn = true;
		notify();
	}
}

class Odd extends Thread
{
	private Buffer buffer;
	private int max;

	Odd(Buffer buffer, int max)
	{
		this.buffer = buffer;
		this.max = max;
	}

	public void run()
	{
		for(int i = 1; i <= max; i = i + 2)
		{
			buffer.printOdd(i);

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

class Even extends Thread
{
	private Buffer buffer;
	private int max;

	Even(Buffer buffer, int max)
	{
		this.buffer = buffer;
		this.max = max;
	}

	public void run()
	{
		for(int i = 2; i <= max; i = i + 2)
		{
			buffer.printEven(i);

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

public class OddEvenDemo
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


		Odd T1 = new Odd(buffer, max);

		Even T2 = new Even(buffer, max);


		T1.start();

		T2.start();
	}
}
