// Singleton class
public class Printer {
   
    private static Printer instance;

    private Printer() {
        System.out.println("Printer is ready.");
    }

    public static Printer getInstance() {
 System.out.println(instance);

        if (instance == null) {
            instance = new Printer(); 
        }

        return instance;
    }

        public void print(String message) {
        System.out.println("Printing: " + message);
    }
}
