package pack1;

public interface MyInterface {
    void abstractMethod();  // Must be implemented
    
    default void defaultMethod() {
        System.out.println("\nDefault method from MyInterface");
    }
}
