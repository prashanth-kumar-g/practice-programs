import java.util.*;

class Driver
{
	private int driverId;
	private String driverName;
	private String driverContact;
	private float driverExperience;
	
	public Driver(int driverId, String driverName, String driverContact, float driverExperience)
	{
		this.driverId = driverId;
		this.driverName = driverName;
		this.driverContact = driverContact;
		this.driverExperience = driverExperience;
	}
	
	public void setDriverId(int driverContact)
	{
		this.driverId = driverId;
	}
	
	public void setDriverName(String driverName)
	{
		this.driverName = driverName;
	}
	
	public void setDriverContact(String driverContact)
	{
		this.driverContact = driverContact;
	}
	
	public void setDriverExperience(float driverExperience)
	{
		this.driverExperience = driverExperience;
	}
	
	public int getDriverId()
	{
		return driverId;
	}
	
	public String getDriverName()
	{
		return driverName;
	}
	
	public String getDriverContact()
	{
		return driverContact;
	}
	
	public float getDriverExperience()
	{
		return driverExperience;
	}
}

class Truck
{
	private int truckId;
	private String truckName;
	private float totalMilesTraveledByTruck;
	private Driver driver;
	
	public Truck(int truckId, String truckName, float totalMilesTraveledByTruck, Driver driver)
	{
		this.truckId = truckId;
		this.truckName = truckName;
		this.totalMilesTraveledByTruck = totalMilesTraveledByTruck;
		this.driver = driver;
	}
	
	public void setTruckId(int truckId)
	{
		this.truckId = truckId;
	}
	
	public void setTruckName(String truckName)
	{
		this.truckName = truckName;
	}
	
	public void setTotalMilesTraveledByTruck(float totalMilesTraveledByTruck)
	{
		this.totalMilesTraveledByTruck = totalMilesTraveledByTruck;
	}
	
	public void setDriver(Driver driver)
	{
		this.driver = driver;
	}
	
	public int getTruckId()
	{
		return truckId;
	}
	
	public String getTruckName()
	{
		return truckName;
	}
	
	public float getTotalMilesTraveledByTruck()
	{
		return totalMilesTraveledByTruck;
	}
	
	public Driver getDriver()
	{
		return driver;
	}
}

public class IPAExam2
{
	public static Truck[] getAllTrucksByDistance(List<Truck> trucks, float distance)
	{
		List<Truck> list = new ArrayList<>();
		
		for(Truck t : trucks)
		{
			if(t.getTotalMilesTraveledByTruck() >= distance)
			{
				list.add(t);
			}
		}
		
		if(list.isEmpty())
		{
			return null;
		}
		
		list.sort((a,b) -> Float.compare(b.getDriver().getDriverExperience(), a.getDriver().getDriverExperience()));
		
		return list.toArray(new Truck[0]);
	}	
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		List<Truck> trucks = new ArrayList<>();
		
		for(int i = 0; i < n; i++)
		{
			int driverId = sc.nextInt();	sc.nextLine();
			String driverName = sc.nextLine();
			String driverContact = sc.nextLine();
			float driverExperience = sc.nextFloat();
			
			int truckId = sc.nextInt();		sc.nextLine();
			String truckName = sc.nextLine();
			float totalMilesTraveledByTruck = sc.nextFloat();
			
			Driver driver = new Driver(driverId, driverName, driverContact, driverExperience);
			Truck truck = new Truck(truckId, truckName, totalMilesTraveledByTruck, driver);
			
			trucks.add(truck);
		}
		
		float distance = sc.nextFloat();
		
		Truck[] result = getAllTrucksByDistance(trucks, distance);
		
		if(result != null)
		{
				for(Truck t : result)
				{
					System.out.println(t.getTruckId());
					System.out.println(t.getTruckName());
					System.out.println(t.getTotalMilesTraveledByTruck());
					System.out.println(t.getDriver().getDriverId());
					System.out.println(t.getDriver().getDriverName());
				}
		}
		else
		{
			System.out.println("No Truck Found");
		}
		
		sc.close();
	}
}