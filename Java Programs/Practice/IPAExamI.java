import java.util.*;

public class IPAExamI
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int n = sc.nextInt();
		int r = sc.nextInt();
		
		if(r < 1)
		{
			System.out.println("Geometric progression cannot be generated for these inputs");
			return;
		}
		
		for(int i = 0; i < n; i++)
		{
			System.out.println(a);
			a = a * r;
		}
		
		sc.close();
	}
}
