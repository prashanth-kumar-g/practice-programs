class Box
{

   double height;
   double width;
   double depth;
}

class BoxDemo
{
  public static void main(String args[])
  {

     Box b1 = new Box();
     b1.height=10;
     b1.width = 15;
     b1.depth = 20;

     double vol;

    vol = b1.height*b1.width*b1.depth;

   System.out.println(vol);
}
}
     