package pack1;

public class ClassInSamePackage {
    public void testSamePackageAccess() {
        SameClass obj = new SameClass();
        System.out.println("\nClassInSamePackage (p1) Access:");
        System.out.println("  defaultVar = " + obj.defaultVar);   // Works (same package)
        // System.out.println("  privateVar = " + obj.privateVar); // ERROR: private (no getter)
        System.out.println("  protectedVar = " + obj.protectedVar); // Works
        System.out.println("  publicVar = " + obj.publicVar);     // Works
    }
}
