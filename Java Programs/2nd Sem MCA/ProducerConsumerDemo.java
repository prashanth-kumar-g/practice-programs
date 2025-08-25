class Buffer
{
	private int data;
	private boolean isEmpty = true;

	synchronized public void produce(int value)
	{
		while(!isEmpty)
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

		data = value;
 		System.out.println("\n Produced : " + data);
		isEmpty = false;
		notify();
	}

	synchronized public void consume()
	{
		while(isEmpty)
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

 		System.out.println("\n Consumed : " + data + "\n");
		isEmpty = true;
		notify();
	}
}

class Producer extends Thread
{
	private Buffer buffer;
	private int max;

	Producer(Buffer buffer, int max)
	{
		this.buffer = buffer;
		this.max = max;
	}

	public void run()
	{
		for(int i = 1; i <= max; i++)
		{
			buffer.produce(i);

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

class Consumer extends Thread
{
	private Buffer buffer;
	private int max;

	Consumer(Buffer buffer, int max)
	{
		this.buffer = buffer;
		this.max = max;
	}

	public void run()
	{
		for(int i = 1; i <= max; i++)
		{
			buffer.consume();

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

public class ProducerConsumerDemo
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


		Producer producer = new Producer(buffer, max);

		Consumer consumer = new Consumer(buffer, max);


		producer.start();

		consumer.start();
	}
}
