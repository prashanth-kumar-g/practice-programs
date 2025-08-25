// NonGen is functionally equivalent to Gen
// but does not use generics.
class NonGen {
 Object ob; 
 NonGen(Object o) {
 ob = o;
 }
 
 Object getob() {
 return ob;
 }
 void showType() {
 System.out.println("Type of ob is " +
 ob.getClass().getName());
 }
}
// Demonstrate the non-generic class.
class NonGenDemo {
 public static void main(String args[]) {
 NonGen iOb;
 // Create NonGen Object and store
 // an Integer in it. Autoboxing still occurs.
 iOb = new NonGen(88);
 // Show the type of data used by iOb.
 iOb.showType();
 
 int v = (Integer) iOb.getob();
 System.out.println("value: " + v);
 

 NonGen strOb = new NonGen("Non-Generics Test");
 
 strOb.showType();
 
String str = (String) strOb.getob();
 System.out.println("value: " + str);
 // This compiles, but is conceptually wrong!
 iOb = strOb;
 v = (Integer) iOb.getob(); // run-time error!
 }
}