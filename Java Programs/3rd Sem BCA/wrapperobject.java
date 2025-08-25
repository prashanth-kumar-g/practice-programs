public class wrapperobject
{
public static void main(String args[])
{
int i=100;
Integer i1= new Integer(i);
Integer i2=Integer.valueOf("200");
System.out.println("The primitive value of i1= "+i1.intValue());
System.out.println("The primitive value of i2= "+i2.intValue());
String str1="12345";
int num2=Integer.parseInt(str1);
System.out.println("The value of num2="+num2);
System.out.println("The string value of i1= "+i1.toString());
System.out.println("The string value of i2= "+i2.toString());
}
}