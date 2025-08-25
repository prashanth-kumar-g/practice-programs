import java.util.Scanner;
public class fibonacci
{
 public static void main(String arg[])
 {
 int fib1=0,fib2=1,temp=0,num;
 Scanner sc= new Scanner(System.in);
 System.out.println("Enter the number of terms");
 num=sc.nextInt();
 System.out.println("The fibonacci Series...");
 System.out.println(fib1);
 System.out.println(fib2);
 for (int i=2;i<num;i++)
 {
 temp=fib1+fib2;
 System.out.println(temp);
 fib1=fib2;
 fib2 = temp;
 }
 }
}
