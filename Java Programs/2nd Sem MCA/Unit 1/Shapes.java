class Figure
{
	double dim1;
	double dim2;

	Figure(double a, double b)
	{
		dim1=a;
		dim2=b;
	}
	double area()
	{
		System.out.println("Inside Figure.");
		return dim1*dim2;
	}
}

class Rectangle extends Figure
{
	Rectangle(double a, double b)
	{
		super(a,b);
	}
	double area()
	{
		return dim1*dim2;
	}
}

class Triangle extends Figure
{
	Triangle(double a, double b)
	{
		super(a,b);
	}
	double area()
	{
System.out.println("Inside Area for Triangle.");
return dim1 * dim2 / 2;
	}
}

class Shapes
{
   public static void main(String args[])
   {
	//this is illegal
	Figure figref = new Figure(10,20);
	Rectangle r = new Rectangle(30,40);
	Triangle t = new Triangle(50,60);
	Figure f;
figref = r;
System.out.println("Area is " + figref.area());
figref = t;
System.out.println("Area is " + figref.area());
figref = figref;
System.out.println("Area is " + figref.area());
   }

}