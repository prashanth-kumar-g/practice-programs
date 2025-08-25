// Class that implements Runnable
class MyRunnableTask implements Runnable {
    public void run() {
        try {
            System.out.println("Thread is running...");

            Thread.sleep(1000);

            System.out.println("Thread has finished execution.");
        } catch (InterruptedException e) {
            System.out.println("Thread was interrupted.");
        }
    }
}

public class ThreadStateExample {
    public static void main(String[] args) {

      
        MyRunnableTask task = new MyRunnableTask();

      
        Thread thread = new Thread(task);

      
        System.out.println("State before start: " + thread.getState()); 

        
        thread.start();

        
        while (thread.isAlive()) {
            System.out.println("State while running: " + thread.getState());
            try {
                Thread.sleep(100); // Small delay for clearer output
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // After the thread has finished
        System.out.println("Final state: " + thread.getState()); 
    }
}
