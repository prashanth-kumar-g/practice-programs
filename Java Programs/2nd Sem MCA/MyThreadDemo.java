class Buffer
{
	public void increment(String name, int max)
	{
		for(int i = 1; i <= max; i++)
		{
			Thread t = Thread.currentThread();

			System.out.println(name + "(Priority : " + t.getPriority() + ") - Count : " + i);

			try
			{
				Thread.sleep(1000);
			}
			catch(InterruptedException e)
			{
				System.out.println(e);
			}
		}
	}
}

class MyThread implements Runnable
{
	private Buffer buffer;
	private int max;

	MyThread(Buffer buffer, int max)
	{
		this.buffer = buffer;
		this.max = max;
	}

	public void run()
	{
		Thread t = Thread.currentThread();


		synchronized(buffer)
		{
			System.out.println("\n" + t.getName() + " isAlive() : " + t.isAlive());
			buffer.increment(t.getName(), max);
			System.out.println(t.getName() + " finished");
		}

	}
}

public class MyThreadDemo
{
	public static void main(String [] args)
	{
		Buffer buffer = new Buffer();


		if(args.length < 1)
		{
			System.out.println("\n A command-line argument is required to give the max limit. \n");
			return;
		}

		int max = Integer.parseInt(args[0]);


		MyThread obj1 = new MyThread(buffer, max);

		Thread T1 = new Thread(obj1);


		MyThread obj2 = new MyThread(buffer, max);

		Thread T2 = new Thread(obj2);


		T1.setName("Thread A");
		T2.setName("Thread B");

		T1.setPriority(3);
		T2.setPriority(4);

		System.out.println("\n" + T1.getName() + " isAlive() : " + T1.isAlive());
		System.out.println(T2.getName() + " isAlive() : " + T2.isAlive());

		T1.start();
		T2.start();

		try
		{
			T1.join();
			T2.join();
		}
		catch(InterruptedException e)
		{
			System.out.println(e);
		}

		System.out.println("\n" + T1.getName() + " isAlive() : " + T1.isAlive());
		System.out.println(T2.getName() + " isAlive() : " + T2.isAlive() + "\n");
	}
}

