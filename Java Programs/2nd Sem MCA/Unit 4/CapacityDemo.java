import java.util.ArrayList;

public class CapacityDemo {
    public static void main(String[] args) {
        // Create an ArrayList with initial capacity of 2
        ArrayList<String> list = new ArrayList<>(10);

        // Ensure capacity of at least 10
        list.ensureCapacity(2);
       

        // Add 3 elements
        list.add("Apple");
       





        // Current size of ArrayList
        System.out.println("List: " + list);
        System.out.println("Size (number of elements): " + list.size());

        // Trim the capacity to match current size
        list.trimToSize();
        System.out.println("Trimmed internal capacity to match size."+list.size());
    }
}
