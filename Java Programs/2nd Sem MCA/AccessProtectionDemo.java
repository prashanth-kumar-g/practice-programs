import pack1.*;

import pack2.*;

public class AccessProtectionDemo implements MyInterface {
    
    public void abstractMethod() {
        System.out.println("Implemented abstractMethod() from MyInterface in Demo");
    }

    public static void main(String[] args) {
        AccessProtectionDemo demo = new AccessProtectionDemo();
        
        // Interface methods
        demo.abstractMethod();  // Calls implemented method
        demo.defaultMethod();   // Calls default method
        
        // Original access control tests
        SameClass sameClass = new SameClass();
        sameClass.printSameClassAccess();

        ClassInSamePackage samePackage = new ClassInSamePackage();
        samePackage.testSamePackageAccess();

        SubClassInSamePackage subClassSamePackage = new SubClassInSamePackage();
        subClassSamePackage.testSubClassAccess();

        SubClassInOtherPackage subClassOtherPackage = new SubClassInOtherPackage();
        subClassOtherPackage.testCrossPackageSubClassAccess();

        ClassInOtherPackage otherPackage = new ClassInOtherPackage();
        otherPackage.testOtherPackageAccess();
    }
}
