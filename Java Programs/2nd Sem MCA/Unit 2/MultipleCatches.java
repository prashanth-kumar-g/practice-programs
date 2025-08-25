class MultipleCatches 
{
  public static void main(String args[])
  {
    try
    {
    int a = args.length;
    System.out.println("The value of a is : "+a);
    int b = 42/a;
    int c[] = {1};
    
    c[18]=45;
    }
    catch(ArithmeticException e)
    {
      System.out.println("Division by 0 "+e);
    }
    catch(ArrayIndexOutOfBoundsException e)
    {
      System.out.println("Array Index Out of Bounds "+e);
    }
  
    System.out.println("Out of try catch block");

        
  }
}








