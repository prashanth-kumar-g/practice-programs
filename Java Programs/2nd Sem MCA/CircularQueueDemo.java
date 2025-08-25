import java.util.Scanner;

interface CircularQueue
{
	void enqueue(int data);
	int dequeue();
	int front();
	int rear();
	void display();
}

class MyCircularQueue implements CircularQueue
{
	private int [] circularQueue;
	private int front = -1, rear = -1;
	private int size;

	MyCircularQueue(int size)
	{
		this.size = size;
		circularQueue = new int[size];
	}

	public void enqueue(int data)
	{
		if( (rear + 1) % size == front )
		{
			System.out.println("\n Circular Queue Overlow, Circular Queue is Full.");
		}
		else if(front == -1 && rear == -1)
		{
			front = rear = 0;

			circularQueue[rear] = data;

			System.out.println("\n Enqueued Element to Circular Queue : " + circularQueue[rear]);
		}
		else
		{
			rear = (rear + 1) % size;

			circularQueue[rear] = data;

			System.out.println("\n Enqueued Element to Circular Queue : " + circularQueue[rear]);
		}
	}

	public int dequeue()
	{
		if( front == -1 && rear == -1 )
		{
			return '\0';
		}
		else if( front == rear)
		{
			int element = circularQueue[front];

			front = rear = -1;

			return element;
		}
		else
		{
			int element = circularQueue[front];

			front = (front + 1) % size;

			return element;
		}
	}

	public int front()
	{
		if( front == -1 && rear == -1 )
		{
			return '\0';
		}
		else
		{
			return circularQueue[front];
		}
	}

	public int rear()
	{
		if( front == -1 && rear == -1 )
		{
			return '\0';
		}
		else
		{
			return circularQueue[rear];
		}
	}

	public void display()
	{
		if( front == -1 && rear == -1 )
		{
			System.out.println("\n Circular Queue is Empty");
		}
		else
		{
			System.out.print("\n The Elements of Circular Queue : ");

			int i = front;

			while(i != rear)
			{
				System.out.print(circularQueue[i] + "  ");

				i = (i + 1) % size;
			}
			System.out.println(circularQueue[rear]);
		}
	}
}

public class CircularQueueDemo
{
	public static void main(String [] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter the Size of Circular Queue : ");
		int size = sc.nextInt();

		MyCircularQueue circularQueue = new MyCircularQueue(size);
		int choice, element;

		while(true)
		{
			System.out.println("\n---------------------------------------------------------------------------------------");
			System.out.println("                                CIRCULAR QUEUE OPERATIONS                                ");
			System.out.println("                               ---------------------------                             \n");
			System.out.println("     1) Enqueue     2) Dequeue     3) Front     4) Rear     5) Display     6) Exit       ");
			System.out.println("\n---------------------------------------------------------------------------------------");

			System.out.print("\n Enter your choice : ");
			choice = sc.nextInt();

			switch(choice)
			{
				case 1: System.out.print("\n Enter the Element to be Enqueued : ");
					element = sc.nextInt();
					circularQueue.enqueue(element);
					break;

				case 2: element = circularQueue.dequeue();
					if(element == '\0')
					{
						System.out.println("\n Circular Queue Underflow, Circular Queue is Empty.");
					}
					else
					{
						System.out.println("\n Dequeued Element from Circular Queue : " + element);
					}
					break;

				case 3: element = circularQueue.front();
					if(element == '\0')
					{
						System.out.println("\n Circular Queue is Empty");
					}
					else
					{
						System.out.println("\n Front Element of Circular Queue : " + element);
					}
					break;

				case 4: element = circularQueue.rear();
					if(element == '\0')
					{
						System.out.println("\n Circular Queue is Empty");
					}
					else
					{
						System.out.println("\n Rear Element of Circular Queue : " + element);
					}
					break;

				case 5: circularQueue.display();
					break;

				case 6: System.out.println("\n Exiting... \n");
					sc.close();
					return;

				default: System.out.println("\n Invalid Choice, Select Again.");
					 break;
			}
		}
	}
}
