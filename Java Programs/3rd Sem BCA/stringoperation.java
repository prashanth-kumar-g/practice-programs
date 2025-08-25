class stringoperation
{
public static void main(String args[])
{
String s1="java";
String s2="programming";
System.out.println("String s1= "+s1);
System.out.println("String s2= "+s2);
int l1 = s1.length();
int l2 = s2.length();
System.out.println("Length of String s1 is "+l1);
System.out.println("Length of String s2 is "+l2);
System.out.println("Concatenation of 2 strings= "+s1.concat(s2));
System.out.println("First charector of "+s1+" is "+s1.charAt(0));
System.out.println("Uppercase of "+s1+" is "+s1.toUpperCase());
System.out.println("Lowercase of "+s1+" is "+s1.toLowerCase());
System.out.println("Occurance of v in "+s1+" is "+s1.indexOf("v"));
System.out.println("Substring of "+s2+" starting from index 3 and ending at 6 is = "+s2.substring(3,7));
System.out.println("Replacing 'o' with w in "+s2+" is "+s2.replace('o','w'));
boolean check = s1.equals(s2);
if(check==false)
System.out.println(s1+" and "+s2+" are not same");
else
System.out.println(s1+" and "+s2+" are same");
}
}
