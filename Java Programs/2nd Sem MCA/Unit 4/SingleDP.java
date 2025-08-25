
public class SingleDP {
    public static void main(String[] args) {
        Printer p1 = Printer.getInstance();
        p1.print("Hello, World!");

        Printer p2 = Printer.getInstance();
        p2.print("Java Design Patterns");

     
        System.out.println(p1 == p2); 
    }
}

