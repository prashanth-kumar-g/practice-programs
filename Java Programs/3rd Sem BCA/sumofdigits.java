import java.io.*;
import java.util.*;
public class sumofdigits
{
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter A Number");
int number= sc.nextInt();
int sum=0;
int input=number;
while (input!=0)
{
int lastdigit=input%10;
sum+=lastdigit;
input/=10;
}
System.out.println("Sum of digit of number "+number+" is " +sum);
sc.close();
}
}