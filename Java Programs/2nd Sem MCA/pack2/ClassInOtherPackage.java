package pack2;

import pack1.SameClass;

public class ClassInOtherPackage {
    public void testOtherPackageAccess() {
        SameClass obj = new SameClass();
        System.out.println("\nClassInOtherPackage (p2) Access:");
        // System.out.println("  defaultVar = " + obj.defaultVar); // ERROR: default
        // System.out.println("  privateVar = " + obj.privateVar); // ERROR: private
        // System.out.println("  protectedVar = " + obj.protectedVar); // ERROR: protected
        System.out.println("  publicVar = " + obj.publicVar);     // Works
    }
}
