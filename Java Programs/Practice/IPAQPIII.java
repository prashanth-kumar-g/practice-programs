import java.util.*;

class Point
{
	private double x;
	private double y;

	public Point(double x, double y)
	{
		this.x = x;
		this.y = y;
	}

	public double getX()
	{
		return x;
	}

	public double getY()
	{
		return y;
	}

	public void setX(double x)
	{
		this.x = x;
	}

	public void setY(double y)
	{
		this.y = y;
	}
}

public class IPAQPIII
{
	public static Point pointWithHighestOriginDistance(Point p1, Point p2, Point p3)
	{
		Point maxPoint;
		
		double dist1 = Math.sqrt((p1.getX() * p1.getX()) + (p1.getY() * p1.getY()));
		
		double dist2 = Math.sqrt((p2.getX() * p2.getX()) + (p2.getY() * p2.getY()));
		
		double dist3 = Math.sqrt((p3.getX() * p3.getX()) + (p3.getY() * p3.getY()));
		
		if (dist1 > dist2 && dist1 > dist3)
		{
			maxPoint = p1;
		}
		else if(dist2 > dist1 && dist2 > dist3)
		{
			maxPoint = p2;
		}
		else
		{
			maxPoint = p3;
		}
		
		return maxPoint;
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		double x1 = sc.nextDouble();
		double y1 = sc.nextDouble();
		
		double x2 = sc.nextDouble();
		double y2 = sc.nextDouble();
		
		double x3 = sc.nextDouble();
		double y3 = sc.nextDouble();
		
		Point p1 = new Point(x1, y1);
		Point p2 = new Point(x2, y2);
		Point p3 = new Point(x3, y3);
		
		Point result = pointWithHighestOriginDistance(p1, p2, p3);
		
		System.out.println(result.getX());
		System.out.println(result.getY());
		
		sc.close();
	}
}
