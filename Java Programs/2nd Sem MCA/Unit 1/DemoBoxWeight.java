class Box
{
	double height;
	double width;
	double depth;
	
	Box(Box ob)
	{
		height=ob.height;
		width=ob.width;
		depth=ob.depth;
		
	}
	Box(double w, double h, double d)
	{
		width=w;
		height=h;
		depth=d;
	}
	Box()
	{
		width=-1;
		depth=-1;
		height=-1;
	}
	Box(double len)
	{
		width=height=depth=len;
	}
	double volume()
	{
		return width*height*depth;
	}
}
class BoxWeight extends Box
{
        double weight;
	BoxWeight(double w, double h, double d, double m)
	{
		height=h;
		width=w;
		weight=m;
		depth=d;
	}
}
class DemoBoxWeight
{
	public static void main(String args[])
	{
		BoxWeight bw1 = new BoxWeight(10,20,15,34.3);
		BoxWeight bw2 = new BoxWeight(2,3,4,0.076);
		double vol;
		vol = bw1.volume();
		System.out.println("The volume is :" + vol);
		System.out.println("The weight is :" + bw1.weight);
	}
}