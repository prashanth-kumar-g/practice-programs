class MyThread extends Thread {
    String name;

    MyThread(String threadName) {
        name = threadName;
    }

    public void run() {
        for (int i = 1; i <= 3; i++) {
            System.out.println(name + " is running: Step " + i);
            try {
                Thread.sleep(500); // Simulate work
            } catch (InterruptedException e) {
                System.out.println(name + " was interrupted.");
            }
        }
        System.out.println(name + " has finished.");
    }
}

public class JoinDemo {
    public static void main(String[] args) {
        MyThread t1 = new MyThread("Thread-1");
        MyThread t2 = new MyThread("Thread-2");

        t1.start();

        try {
            t1.join(); // Wait for t1 to finish
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted while waiting for t1.");
        }

        t2.start(); // Starts only after t1 is done

        try {
            t2.join(); // Wait for t2 to finish
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted while waiting for t2.");
        }

        System.out.println("Main thread ends after both threads complete.");
    }
}
