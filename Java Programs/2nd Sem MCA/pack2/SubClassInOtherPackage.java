package pack2;

import pack1.SameClass;

public class SubClassInOtherPackage extends SameClass {
    public void testCrossPackageSubClassAccess() {
        System.out.println("\nSubClassInOtherPackage (p2) Access:");
        // System.out.println("  defaultVar = " + defaultVar); // ERROR: default
        // System.out.println("  privateVar = " + privateVar); // ERROR: private (no getter)
        System.out.println("  protectedVar = " + protectedVar); // Works (subclass)
        System.out.println("  publicVar = " + publicVar);       // Works
    }
}
