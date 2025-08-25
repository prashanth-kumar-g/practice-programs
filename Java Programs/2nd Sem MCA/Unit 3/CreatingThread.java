import java.lang.*;
class MyThread extends Thread
{
	public void run()
	  {
   		for(int i=0;i<=5;i++)
		{
		   System.out.println("Child thread");
		}
          }


}
class CreatingThread
{
   public static void main(String args[])
	{
	   MyThread obj = new MyThread();
	   obj.start();
	   for(int i=0;i<=5;i++)
		{
		   System.out.println("Main thread");
		}

}


}