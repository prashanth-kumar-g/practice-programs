@FunctionalInterface
interface A
{
	void show();
	String toString();
void display();
	
}

//class B implements A
//{
	//public void show()
		//{
			//System.out.println("Hii");
		//}
//}

class Demo
{
	public static void main(String args[])
	{
		A obj = () -> System.out.println("Hii inside Anonymous");
				
			
		obj.show();
	}


}