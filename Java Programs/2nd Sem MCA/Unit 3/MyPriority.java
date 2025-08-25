class MyPriority extends Thread
{
   public void run()
    {
      System.out.println("run method");
     }
public static void main(String args[])
 {
   MyPriority t1 = new MyPriority();
   MyPriority t2 = new MyPriority();
   MyPriority t3 = new MyPriority();

   t1.setPriority(Thread.MIN_PRIORITY);
   t2.setPriority(Thread.MAX_PRIORITY);
   t3.setPriority(Thread.NORM_PRIORITY);

   System.out.println("t1 priority: "+t1.getPriority());
   System.out.println("t2 priority: "+t2.getPriority());
   System.out.println("t3 priority: "+t3.getPriority());
 }
}