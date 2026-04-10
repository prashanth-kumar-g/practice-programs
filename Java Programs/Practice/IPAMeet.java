import java.util.*;

// Brand class
class Brand 
{
    private int brandId;
    private String brandName;
    private double rating;

    public Brand(int brandId, String brandName, double rating) 
	{
        this.brandId = brandId;
        this.brandName = brandName;
        this.rating = rating;
    }

    public int getBrandId() 
	{
        return brandId;
    }

    public String getBrandName() 
	{
        return brandName;
    }

    public double getRating() 
	{
        return rating;
    }
}

// Chair class
class Chair 
{
    private int chairId;
    private String type;
    private double price;
    private Brand brand;

    public Chair(int chairId, String type, double price, Brand brand) 
	{
        this.chairId = chairId;
        this.type = type;
        this.price = price;
        this.brand = brand;
    }

    public int getChairId() 
	{
        return chairId;
    }

    public String getType() 
	{
        return type;
    }

    public double getPrice() 
	{
        return price;
    }

    public Brand getBrand() 
	{
        return brand;
    }

    public void setPrice(double price) 
	{
        this.price = price;
    }
}

// Business class
class Business 
{
    // Find most expensive chair of given brand
    public static List<Chair> findMostExpensiveChairDetails(List<Chair> chairs, String brandName) 
	{
        List<Chair> result = new ArrayList<>();
        double maxPrice = -1;

        for (Chair c : chairs) 
		{
            if (c.getBrand().getBrandName().equalsIgnoreCase(brandName)) 
			{
                if (c.getPrice() > maxPrice) 
				{
                    maxPrice = c.getPrice();
                }
            }
        }

        if (maxPrice == -1) 
		{
            return null;
        }

        for (Chair c : chairs) 
		{
            if (c.getBrand().getBrandName().equalsIgnoreCase(brandName) && c.getPrice() == maxPrice) 
			{
                result.add(c);
            }
        }

        return result;
    }

    // Apply discount
    public static List<Chair> calculateDiscountedPrice(List<Chair> chairs, String brandName, double discount) 
	{
        List<Chair> result = new ArrayList<>();

        for (Chair c : chairs) 
		{
            if (c.getBrand().getBrandName().equalsIgnoreCase(brandName)) 
			{
                double newPrice = c.getPrice() - (c.getPrice() * discount / 100);
                c.setPrice(newPrice);

                result.add(c);
            }
        }

        if (result.isEmpty()) 
		{
            return null;
        }

        return result;
    }
}

// Solution class
public class IPAMeet 
{
    public static void main(String[] args) 
	{
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());

        List<Chair> chairs = new ArrayList<>();

        for (int i = 0; i < n; i++) 
		{
            int brandId = Integer.parseInt(sc.nextLine());
            String brandName = sc.nextLine();
            double rating = Double.parseDouble(sc.nextLine());

            Brand brand = new Brand(brandId, brandName, rating);

            int chairId = Integer.parseInt(sc.nextLine());
            String type = sc.nextLine();
            double price = Double.parseDouble(sc.nextLine());

            Chair chair = new Chair(chairId, type, price, brand);
            chairs.add(chair);
        }

        String searchBrand = sc.nextLine();
        double discount = Double.parseDouble(sc.nextLine());

        // 1. Most Expensive Chair
        List<Chair> expensiveChairs = Business.findMostExpensiveChairDetails(chairs, searchBrand);

        if (expensiveChairs == null) 
		{
            System.out.println("Matching brand is not available in the list");
        } 
		else 
		{
            for (Chair c : expensiveChairs) 
			{
                System.out.println("BrandName: " + c.getBrand().getBrandName() + ", ChairType: " + c.getType() + ", Price: " + (int)c.getPrice());
            }
        }

        // 2. Discounted Chairs
        List<Chair> discountedChairs = Business.calculateDiscountedPrice(chairs, searchBrand, discount);

        if (discountedChairs == null) 
		{
            System.out.println("Matching brand is not available in the list");
        } 
		else 
		{
            System.out.println("Discounted Chairs:");
        
			for (Chair c : discountedChairs) 
			{
                System.out.println("BrandName: " + c.getBrand().getBrandName() + ", ChairType: " + c.getType() + ", Updated Price: " + (int)c.getPrice());
            }
        }

        sc.close();
    }
}