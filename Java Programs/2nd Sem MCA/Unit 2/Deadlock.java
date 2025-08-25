class A
{
  synchronized void foo(B b)
  {
     String name = Thread.currentThread().getName();
     System.out.println("Thread inside A class is "+name);

     try
     {
       Thread.sleep(1000);
     }
     catch(InterruptedException e)
     {
       System.out.println("Exception is "+e);
     }
     System.out.println("Trying to call b.last "+name);
     b.last();
  }
  synchronized void last()
  {
    System.out.println("Inside the last of A method");     
  }
}
class B
{
  synchronized void bar(A a)
  {
     String name = Thread.currentThread().getName();
     System.out.println("Thread inside B class is "+name);

     try
     {
       Thread.sleep(1000);
     }
     catch(InterruptedException e)
     {
       System.out.println("Exception is "+e);
     }
     System.out.println("Trying to call a.last "+name);
     //a.last();
  }
  synchronized void last()
  {
    System.out.println("Inside the last of B method");     
  }
}

class Deadlock implements Runnable
{
  A a = new A();
  B b = new B();
  Thread t;

  Deadlock()
  {
    Thread.currentThread().setName("Main Thread");
    t = new Thread(this, "Racing Thread");

  }

  void deadlockStart()
  {
    t.start();
    a.foo(b);
    System.out.println("Back inside main thread");  
  }

  public void run()
  {
    b.bar(a);
    System.out.println("Inside another thread");
  }

  public static void main(String args[])
  {
    Deadlock dl = new Deadlock();
    dl.deadlockStart();
  }
}