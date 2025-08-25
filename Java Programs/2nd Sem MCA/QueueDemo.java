import java.util.Scanner;

interface Queue
{
	void enqueue(int data);
	int dequeue();
	int front();
	int rear();
	void display();
}

class MyQueue implements Queue
{
	private int [] queue;
	private int front = -1, rear = -1;
	private int size;

	MyQueue(int size)
	{
		this.size = size;
		queue = new int[size];
	}

	public void enqueue(int data)
	{
		if(rear == size - 1)
		{
			System.out.println("\n Queue Overlow, Queue is Full.");
		}
		else
		{
			if(front == -1)
			{
				front = 0;
			}

			queue[++rear] = data;
			System.out.println("\n Enqueued Element to Queue : " + queue[rear]);
		}
	}

	public int dequeue()
	{
		if(rear == -1 || front > rear)
		{
			return '\0';
		}
		else
		{
			return queue[front++];
		}
	}

	public int front()
	{
		if(rear == -1 || front > rear)
		{
			return '\0';
		}
		else
		{
			return queue[front];
		}
	}

	public int rear()
	{
		if(rear == -1 || front > rear)
		{
			return '\0';
		}
		else
		{
			return queue[rear];
		}
	}

	public void display()
	{
		if(rear == -1 || front > rear)
		{
			System.out.println("\n Queue is Empty");
		}
		else
		{
			System.out.print("\n The Elements of Queue : ");

			for(int i = front; i <= rear; i++)
			{
				System.out.print(queue[i] + "  ");
			}
			System.out.println();
		}
	}
}

public class QueueDemo
{
	public static void main(String [] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter the Size of Queue : ");
		int size = sc.nextInt();

		MyQueue queue = new MyQueue(size);
		int choice, element;

		while(true)
		{
			System.out.println("\n---------------------------------------------------------------------------------------");
			System.out.println("                                     QUEUE OPERATIONS                                    ");
			System.out.println("                                    ------------------                                 \n");
			System.out.println("     1) Enqueue     2) Dequeue     3) Front     4) Rear     5) Display     6) Exit       ");
			System.out.println("\n---------------------------------------------------------------------------------------");

			System.out.print("\n Enter your choice : ");
			choice = sc.nextInt();

			switch(choice)
			{
				case 1: System.out.print("\n Enter the Element to be Enqueued : ");
					element = sc.nextInt();
					queue.enqueue(element);
					break;

				case 2: element = queue.dequeue();
					if(element == '\0')
					{
						System.out.println("\n Queue Underflow, Queue is Empty.");
					}
					else
					{
						System.out.println("\n Dequeued Element from queue : " + element);
					}
					break;

				case 3: element = queue.front();
					if(element == '\0')
					{
						System.out.println("\n Queue is Empty");
					}
					else
					{
						System.out.println("\n Front Element of Queue : " + element);
					}
					break;

				case 4: element = queue.rear();
					if(element == '\0')
					{
						System.out.println("\n Queue is Empty");
					}
					else
					{
						System.out.println("\n Rear Element of Queue : " + element);
					}
					break;

				case 5: queue.display();
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
