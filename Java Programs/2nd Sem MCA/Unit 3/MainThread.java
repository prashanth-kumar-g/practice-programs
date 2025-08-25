class MainThread
{
	public static void main(String args[])
	{
		System.out.println("The main thread");
		Thread t=Thread.currentThread();
		System.out.println(t);
		t.setName("new thread");
		t.setPriority(2);
		System.out.println(t);
	}

}