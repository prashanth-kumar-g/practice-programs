import java.lang.*;
class MyThread implements Runnable
{
	public void run()
	  {
   		for(int i=0;i<=5;i++)
		{
		   System.out.println("Child thread");
		}
          }


}
class CreatingThreadByRunbl
{
   public static void main(String args[])
	{
	   //MyThread obj = new MyThread();
	   Thread t = new Thread();
	   t.start();
	   for(int i=0;i<=5;i++)
		{
		   System.out.println("Main thread");
		}

}


}