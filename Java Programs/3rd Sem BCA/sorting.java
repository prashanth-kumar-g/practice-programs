class sorting
{
public static void main(String args[])
{
int a[]=new int [10];
try
{
for(int i=0;i<5;i++)
a[i]= Integer.parseInt(args[i]);
System.out.println("\nBefore Sorting");
for(int i=0;i<5;i++)
System.out.println(" "+a[i]);
bubblesort(a,5);
System.out.println("\nAfter Sorting");
System.out.println("\nAscending Order");
for(int i=0;i<5;i++)
System.out.println(" "+a[i]);
System.out.println("\nDesending Order");
for(int i=4;i>=0;i--)
System.out.println(" "+a[i]);
}
catch(NumberFormatException e)
{
System.out.println("Enter only integer");
}
catch(ArrayIndexOutOfBoundsException e)
{
System.out.println("Enter only 5 integer");
}
}
private static void bubblesort(int[] a,int l)
{
int temp,i,j;
for(i=0;i<l-1;i++)
{
for(j=0;j<l-i-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}
}
