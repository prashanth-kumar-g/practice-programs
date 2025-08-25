import java.util.*;
class vectoroperations
{
public static void main(String args[])
{
Vector<Integer> v= new Vector<Integer>();
for(int i=0;i<10;i++)
{
v.add(i);
}
System.out.println(v);
System.out.println("After Removal of item 3");
v.remove(3);
System.out.println(v);
System.out.println("Element at index 1 is = "+v.get(1));
System.out.println("First element of the vector is="+v.firstElement());
System.out.println("Last element of the vector is="+v.lastElement());
}
}
