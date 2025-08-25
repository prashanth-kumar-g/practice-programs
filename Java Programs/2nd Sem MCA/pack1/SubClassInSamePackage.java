package pack1;

public class SubClassInSamePackage extends SameClass {
    public void testSubClassAccess() {
        System.out.println("\nSubClassInSamePackage (p1) Access:");
        System.out.println("  defaultVar = " + defaultVar);   // Works (same package)
        // System.out.println("  privateVar = " + privateVar); // ERROR: private (no getter)
        System.out.println("  protectedVar = " + protectedVar); // Works (subclass)
        System.out.println("  publicVar = " + publicVar);     // Works
    }
}
