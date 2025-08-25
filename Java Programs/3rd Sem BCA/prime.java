class prime
{
public static void main(String args[])
{
int i,j;
if(args.length<2)
{
System.out.println("Less command line arguments found");
}
int n1=Integer.parseInt(args[0]);
int n2=Integer.parseInt(args[1]);
System.out.println("Prime numbers between "+n1+" and "+n2+" are : ");
for(i=n1;i<=n2;i++)
{
for(j=2;j<i;j++)
{
if(i%j==0)
{
break;
}
}
if(i==j)
{
System.out.println(i);
}
}
}
}
