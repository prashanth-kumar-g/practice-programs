import java.util.*;

class Laptop
{
	private int laptopId;
	private String brand;
	private String osType;
	private double price;
	private int rating;

	public Laptop(int laptopId, String brand, String osType, double price, int rating)
	{
		this.laptopId = laptopId;
		this.brand = brand;
		this.osType = osType;
		this.price = price;
		this.rating = rating;
	}

	public void setLaptopId(int laptopId)
	{
		this.laptopId = laptopId;
	}

	public void setBrand(String brand)
	{
		this.brand = brand;
	}

	public void setOsType(String osType)
	{
		this.osType = osType;
	}

	public void setPrice(double price)
	{
		this.price = price;
	}

	public void setRating(int rating)
	{
		this.rating = rating;
	}

	 public int getLaptopId()
	{
		return laptopId;
	}

	public String getBrand()
	{
		return brand;
	}

	public String getOsType()
	{
		return osType;
	}

	public double getPrice()
	{
		return price;
	}

	public int getRating()
	{
		return rating;
	}
}

public class IPA2b
{
	public static int countOfLaptopsByBrand(Laptop[] laptops, String brand)
	{
		int count = 0;

		for(Laptop l : laptops)
		{
			if(l.getBrand().equalsIgnoreCase(brand) && l.getRating() > 3)
			{
				count++;
			}
		}

		return count;
	}

	public static Laptop[] searchLaptopByOsType(Laptop[] laptops, String osType)
	{
		List<Laptop> list = new ArrayList<>();

		for(Laptop l : laptops)
		{
			if(l.getOsType().equalsIgnoreCase(osType))
			{
				list.add(l);
			}
		}

		if(list.isEmpty())
		{
			return null;
		}

		list.sort((a, b) -> b.getLaptopId() - a.getLaptopId());

		return list.toArray(new Laptop[0]);
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		Laptop[] laptops = new Laptop[4];

		for(int i = 0; i < 4; i++)
		{
			int id = sc.nextInt();		sc.nextLine();
			String brand = sc.nextLine();
			String osType = sc.nextLine();
			double price = sc.nextDouble();
			int rating = sc.nextInt();	sc.nextLine();

			laptops[i] = new Laptop(id, brand, osType, price, rating);
		}

		String searchBrand = sc.nextLine();
		String searchOsType = sc.nextLine();

		int result1 = countOfLaptopsByBrand(laptops, searchBrand);

		if(result1 != 0)
		{
			System.out.println(result1);
		}
		else
		{
			System.out.println("The given brand is not available");
		}

		Laptop[] result2 = searchLaptopByOsType(laptops, searchOsType);

		if(result2 != null)
		{
			for(Laptop l : result2)
			{
				System.out.println(l.getLaptopId());
				System.out.println(l.getRating());
			}
		}
		else
		{
			System.out.println("The given os is not available");
		}

		sc.close();
	}
}