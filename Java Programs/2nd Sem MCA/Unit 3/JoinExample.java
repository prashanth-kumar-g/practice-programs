class MyThread extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Child thread: " + i);
        }
    }
}

public class JoinExample {
    public static void main(String[] args) throws InterruptedException {
        MyThread t = new MyThread();
	 System.out.println("before start() executing ");
System.out.println(t.isAlive());
        t.start();
	 System.out.println("after start() ");
	System.out.println(t.isAlive());
        // Main thread waits until t completes
        t.join();

        System.out.println("Main thread continues after child thread completes");
    }
}
