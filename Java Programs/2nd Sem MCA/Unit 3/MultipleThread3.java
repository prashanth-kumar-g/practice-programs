class ThreadA implements Runnable
{
   public void run()
   {
     for(int i=0; i<=5; i++)
     {
       System.out.println("ThreadA i= "+ (-1*i));
     }
   }
}
class ThreadB implements Runnable
{
   public void run()
   {
     for(int j=0; j<=5; j++)
     {
       System.out.println("ThreadB j= "+ (2*j));
     }
   }

}
class MultipleThread3
{
  public static void main(String args[])
	{
	    ThreadA obj1 = new ThreadA();
            Thread t1 = new Thread(obj1);
            ThreadB obj2 = new ThreadB();
            Thread t2 = new Thread(obj2);

	    t1.start();
	    t2.start();

	}
}