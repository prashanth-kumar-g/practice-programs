class figure
{
int length,breadth,height;
int volume()
{
return (length*breadth*height);
}
figure()
{
length=breadth=height=2;
System.out.println("No argument constructor");
}
figure(int l,int b)
{
length=l;
breadth=b;
height=2;
System.out.println("Two argument constructor");
}
figure(int l,int b,int h)
{
length=l;
breadth=b;
height=h;
System.out.println("Three argument constructor");
}
public static void main(String args[])
{
figure f1 = new figure();
System.out.println("Voulme of f1 is "+f1.volume());
figure f2 = new figure(10,20);
System.out.println("Voulme of f2 is "+f2.volume());
figure f3 = new figure(10,20,30);
System.out.println("Voulme of f3 is "+f3.volume());
}
}