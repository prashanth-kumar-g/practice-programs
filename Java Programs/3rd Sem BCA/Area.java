import java.io.*;
class Area
{
public static double circleArea(double r)
{
return Math.PI*r*r;
}
public static double squareArea(double r)
{
return r*r;
}
public static double rectArea(double w,double h)
{
return w*h;
}
public static double triArea(double b,double h2)
{
return 0.5*b*h2;
}
public static String readLine()
{
String input=" ";
BufferedReader in=new BufferedReader(new 
InputStreamReader(System.in));
try
{
input=in.readLine();
}
catch(Exception e)
{
System.out.println("error"+e);
}
return input;
}
public static void main(String[] args)
{
System.out.println("Enter the radius value");
double r= Double.parseDouble(readLine());
System.out.println("Area of circle= "+circleArea(r));
System.out.println("Enter the side value");
double s= Double.parseDouble(readLine());
System.out.println("Area of square= "+squareArea(s));
System.out.println("Enter the width value");
double w= Double.parseDouble(readLine());
System.out.println("Enter the height value");
double h= Double.parseDouble(readLine());
System.out.println("Area of rectangle= "+rectArea(w,h));
System.out.println("Enter the base value");
double b= Double.parseDouble(readLine());
System.out.println("Enter the height value");
double h2= Double.parseDouble(readLine());
System.out.println("Area of triangle= "+triArea(b,h2));
}
}