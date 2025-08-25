class MyThread extends Thread {
    String name;

    MyThread(String threadName) {
        name = threadName;
    }

    public void run() {
        for (int i = 1; i <= 3; i++) {
            System.out.println(name + " is running: Step " + i);
            try {
                Thread.sleep(500); // Simulate some work
            } catch (InterruptedException e) {
                System.out.println(name + " was interrupted.");
            }
        }
        System.out.println(name + " has finished.");
    }
}

public class NoJoinDemo {
    public static void main(String[] args) {
        MyThread t1 = new MyThread("Thread-1");
        MyThread t2 = new MyThread("Thread-2");

        t1.start();
        t2.start(); // Starts immediately without waiting for t1

        System.out.println("Main thread ends.");
    }
}
