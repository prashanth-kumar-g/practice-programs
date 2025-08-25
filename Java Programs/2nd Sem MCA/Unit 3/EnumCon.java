enum Apple { Jonathan(10),GoldenDel(9), RedDel, Winesap(15), Cortland(8); 
private int price; 
// Constructor 
Apple(int p) { price = p; } 
Apple() 
{ 
price = -1; 
}
 int getPrice()
 { 
    return price; 
  }
}
class EnumCon
{
public static void main(String args[])
{
	 Apple ap = Apple.GoldenDel;
        System.out.println("Price of " + ap + " is " + ap.getPrice());
}
}