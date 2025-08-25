class MyThread extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Child thread: " + i);
        }
    }
}

public class JoinExample {
    public static void main(String[] args) throws InterruptedException {
        MyThread t1 = new MyThread();
	MyThread t2 = new MyThread();
	MyThread t3 = new MyThread();

	
	 System.out.println("before start executing "+t.isAlive());
        t1.start();

	 //System.out.println("after start() "+t.isAlive());
        // Main thread waits until t completes
	try{
        t1.join();
	}catch(Exception e)
	{
	  System.out.println(" ")
	}
	t2.start();
	t3.start();

        System.out.println("Main thread continues after child thread completes");
    }
}
