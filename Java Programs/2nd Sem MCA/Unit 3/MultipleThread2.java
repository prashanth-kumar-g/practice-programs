class MyThread extends Thread
{
  String name;
  MyThread(String n)
  {
    name=n;
  } 
   public void run()
   {
     for(int i=1;i<=5;i++)
     {
       System.out.println(name+" :"+i);
      }
System.out.println("Exiting from"+name);
   }
   
}
class MultipleThread2
{
  public static void main(String args[])
   {
      MyThread t1 = new MyThread("ThreadA");
      MyThread t2 = new MyThread("ThreadB");

      t1.start();
      t2.start();
   }
}	