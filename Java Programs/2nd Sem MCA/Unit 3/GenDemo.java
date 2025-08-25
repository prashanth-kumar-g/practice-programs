// A simple generic class.
// Here, T is a type parameter that
// will be replaced by a real type
// when an object of type Gen is created.
class Gen<T> {
// declare an object of type T

 T ob; 
 Gen(T o) {
 ob = o;
 }

 T getob() {
 return ob;
 }

void showType() {
 System.out.println("Type of T is " +
 ob.getClass().getName());
 }
}
// Demonstrate the generic class.
class GenDemo {
 public static void main(String args[]) {
 // Create a Gen reference for Integers.
 Gen<Integer> iOb;

 iOb = new Gen<Integer>(88);//autoboxing
 
 iOb.showType();
 
 int v = iOb.getob();
 System.out.println("value: " + v);
 System.out.println();

 // Create a Gen object for Strings.
 Gen<String> strOb = new Gen<String> ("Generics Test");

 strOb.showType();

 String str = strOb.getob();
 System.out.println("value: " + str);
iOb = strOb ;


 }
}