interface bank
{
float rateofinterest();
}
interface institute
{
String institutetype();
}
class sbi implements bank,institute
{
public float rateofinterest()
{
return 9.15f;
}
public String institutetype()
{
return "Public Sector Banks";
}
}
class axis implements bank,institute
{
public float rateofinterest()
{
return 9.7f;
}
public String institutetype()
{
return "Private Sector Banks";
}
}
class testinterface
{
public static void main(String[] args)
{
sbi a=new sbi();
System.out.println("Rate of Interest at SBI: "+a.rateofinterest());
System.out.println("Type of Bank: "+a.institutetype());
axis b=new axis();
System.out.println("Rate of Interest at Axis: "+b.rateofinterest());
System.out.println("Type of Bank: "+b.institutetype());
}
}