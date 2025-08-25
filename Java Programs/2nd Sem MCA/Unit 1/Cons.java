class Box
{
    double height;
    double width;
    double depth;

   Box(double w,double h,double d)
  {
	height = h;
        width = w;
        depth = d;
  }

    double volume()
    {
        return width*height*depth;
    }


}

class Cons
{
    public static void main(String args[])
    {
        //implicit constructor 
	//declare allocate and initialize box object
        Box myBox = new Box(10,20,10);
 
        double vol;
        vol = myBox.volume();
        
        System.out.println("The volume is "+myBox.volume());        

	Box myBox1 = new Box(20,20,10);

        vol = myBox1.volume();
        
        System.out.println("The volume is "+myBox1.volume());  
    }
}







