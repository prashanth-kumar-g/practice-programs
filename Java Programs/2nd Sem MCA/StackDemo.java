import java.util.Scanner;

interface Stack
{
	void push(int data);
	int pop();
	int peek();
	void display();
}

class MyStack implements Stack
{
	private int [] stack;
	private int top = -1;
	private int size;

	MyStack(int size)
	{
		this.size = size;
		stack = new int[size];
	}

	public void push(int data)
	{
		if(top == size - 1)
		{
			System.out.println("\n Stack Overflow, Stack is Full.");
		}
		else
		{
			stack[++top] = data;
			System.out.println("\n Pushed Element to Stack : " + stack[top]);
		}
	}

	public int pop()
	{
		if(top == -1)
		{
			return '\0';
		}
		else
		{
			return stack[top--];
		}
	}

	public int peek()
	{
		if(top == -1)
		{
			return '\0';
		}
		else
		{
			return stack[top];
		}
	}

	public void display()
	{
		if(top == -1)
		{
			System.out.println("\n Stack is Empty");
		}
		else
		{
			System.out.print("\n The Elements of Stack : ");

			for(int i = top; i >= 0; i--)
			{
				System.out.print(stack[i] + "  ");
			}
			System.out.println();
		}
	}
}

public class StackDemo
{
	public static void main(String [] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("\n Enter the Size of Stack : ");
		int size = sc.nextInt();

		MyStack stack = new MyStack(size);
		int choice, element;

		while(true)
		{
			System.out.println("\n-------------------------------------------------------------------");
			System.out.println("                        STACK OPERATIONS                             ");
			System.out.println("                       ------------------                          \n");
			System.out.println("     1) Push     2) Pop     3) Peek     4) Display     5) Exit       ");
			System.out.println("\n-------------------------------------------------------------------");

			System.out.print("\n Enter your choice : ");
			choice = sc.nextInt();

			switch(choice)
			{
				case 1: System.out.print("\n Enter the Element to be Pushed : ");
					element = sc.nextInt();
					stack.push(element);
					break;

				case 2: element = stack.pop();
					if(element == '\0')
					{
						System.out.println("\n Stack Underflow, Stack is Empty.");
					}
					else
					{
						System.out.println("\n Popped Element from Stack : " + element);
					}
					break;

				case 3: element = stack.peek();
					if(element == '\0')
					{
						System.out.println("\n Stack is Empty");
					}
					else
					{
						System.out.println("\n Peek Element of Stack : " + element);
					}
					break;

				case 4: stack.display();
					break;

				case 5: System.out.println("\n Exiting... \n");
					sc.close();
					return;

				default: System.out.println("\n Invalid Choice, Select Again.");
					 break;
			}
		}
	}
}
