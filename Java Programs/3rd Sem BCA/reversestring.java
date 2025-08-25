import java.util.*;
class reversestring
{
public static void main(String args[])
{
String original,reverse="";
Scanner in = new Scanner(System.in);
System.out.println("Enter a string to be reverse");
original=in.nextLine();
int length=original.length();
for(int i=length-1;i>=0;i--)
reverse=reverse+original.charAt(i);
System.out.println("Original : "+original);
System.out.println("Reversed : "+reverse);
in.close();
}
}
