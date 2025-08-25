public class BuiltinDemo {
    public static void setAge(int age) {
        if (age < 0) {
            throw new IllegalArgumentException("Age cannot be negative");
        }
        System.out.println("Age is set to: " + age);
    }

    public static void main(String[] args) {
        setAge(25);  // OK
        setAge(-5);  // Throws IllegalArgumentException
    }
}
