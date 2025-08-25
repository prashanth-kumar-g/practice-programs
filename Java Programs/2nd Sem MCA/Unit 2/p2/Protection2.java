package p2;

class Protection2 extends p1.Protection
{
  Protection2()
  {
    System.out.println("Inside Protection2 Constructor");
    //System.out.println("Value of n "+ n);
    //System.out.println("Value of n_pri "+n_pri);  //Work inside the package p1 not in p2
    System.out.println("Value of n_pro "+n_pro);
    System.out.println("Value of n_pub "+n_pub);
  }
}