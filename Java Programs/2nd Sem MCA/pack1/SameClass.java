package pack1;

public class SameClass {
    int defaultVar = 1;          // Default access
    private int privateVar = 2;  // Private (no getter!)
    protected int protectedVar = 3; // Protected access
    public int publicVar = 4;    // Public access

    // Method to show same-class access (privateVar is visible here)
    public void printSameClassAccess() {
        System.out.println("\nSameClass (p1) Access:");
        System.out.println("  defaultVar = " + defaultVar);
        System.out.println("  privateVar = " + privateVar); // Works (same class only)
        System.out.println("  protectedVar = " + protectedVar);
        System.out.println("  publicVar = " + publicVar);
    }
}
