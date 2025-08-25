class ThrowsDemo
{
  static void throwOne() throws IllegalAccessException
  {
    System.out.println("Inside throwOne");
    throw new IllegalAccessException(" Java Exception ");
  }
  public static void main(String args[])
  {
    try
    {
      throwOne();
    }
    catch(IllegalAccessException e)
    {
      System.out.println("Illegal Access Exception "+ e);
    }
    finally
    {
      System.out.println("At the end of the program");
    }
  }  
}





