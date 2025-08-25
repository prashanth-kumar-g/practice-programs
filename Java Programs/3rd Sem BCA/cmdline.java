public class cmdline
{
public static void main(String args[])
{
if(args.length>=2)
{
int n1=Integer.parseInt(args[0]);
int n2=Integer.parseInt(args[1]);
int sum=n1+n2;
System.out.print("sum " + sum);
}
else
{
System.out.println("Incorrect Input");
}
}
}