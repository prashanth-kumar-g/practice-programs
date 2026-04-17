import java.util.*;

class Hotel 
{
	private int hotelId;
	private String hotelName;
	private String dateOfBooking;
	private int noOfRoomsBooked;
	private String wifiFacility;
	private double totalBill;

    	public Hotel(int hotelId, String hotelName, String dateOfBooking, int noOfRoomsBooked, String wifiFacility, double totalBill)
	{
        		this.hotelId = hotelId;
        		this.hotelName = hotelName;
        		this.dateOfBooking = dateOfBooking;
       		this.noOfRoomsBooked = noOfRoomsBooked;
        		this.wifiFacility = wifiFacility;
        		this.totalBill = totalBill;
    	}

	public void setHotelId(int hotelId) 
	{ 
		this.hotelId = hotelId; 
	}

    	public void setHotelName(String hotelName) 
	{ 
		this.hotelName = hotelName; 
	}
    
	public void setDateOfBooking(String dateOfBooking) 
	{ 
		this.dateOfBooking = dateOfBooking; 
	}
    
	public void setNoOfRoomsBooked(int noOfRoomsBooked) 
	{ 
		this.noOfRoomsBooked = noOfRoomsBooked; 
	}
    
	public void setWifiFacility(String wifiFacility) 
	{ 
		this.wifiFacility = wifiFacility; 
	}

	public void setTotalBill(double totalBill) 
	{ 
		this.totalBill = totalBill; 
	}

	public int getHotelId() 
	{ 
		return hotelId; 
	}
    
	public String getHotelName() 
	{ 
		return hotelName; 
	}
    
	public String getDateOfBooking() 
	{ 
		return dateOfBooking; 
	}
    
	public int getNoOfRoomsBooked() 
	{ 
		return noOfRoomsBooked; 
	}
    
	public String getWifiFacility()
	{ 
		return wifiFacility; 
	}
    	
	public double getTotalBill() 
	{ 
		return totalBill; 
	}
}

public class IPAQP3b
{
	public static int noOfRoomsBookedInGivenMonth(Hotel[] hotels, String month) 
	{
        		int sum = 0;

        		for (Hotel h : hotels) 
		{
            			String[] parts = h.getDateOfBooking().split("-");
            			String m = parts[1];

            			if (m.equalsIgnoreCase(month)) 
			{
                				sum += h.getNoOfRoomsBooked();
            			}
        		}
        		
		return sum;
    	}

    	public static Hotel searchHotelByWifiOption(Hotel[] hotels, String wifi) 
	{
        		List<Hotel> list = new ArrayList<>();

        		for (Hotel h : hotels) 
		{
            			if (h.getWifiFacility().equalsIgnoreCase(wifi)) 
			{
                				list.add(h);
            			}
        		}

        		if (list.size() < 2) 
		{
            			return null;
        		}

        		list.sort((a, b) -> Double.compare(b.getTotalBill(), a.getTotalBill()));

        		return list.get(1);
   	 }

	public static void main(String args[]) 
	{
        		Scanner sc = new Scanner(System.in);

        		Hotel[] hotels = new Hotel[4];

        		for (int i = 0; i < 4; i++) 
		{
            			int id = sc.nextInt();		sc.nextLine();
            			String name = sc.nextLine();
            			String date = sc.nextLine();
            			int rooms = sc.nextInt();	sc.nextLine();
            			String wifi = sc.nextLine();
            			double bill = sc.nextDouble();	sc.nextLine();

			 hotels[i] = new Hotel(id, name, date, rooms, wifi, bill);
        		}

        		String month = sc.nextLine();
        		String wifiOption = sc.nextLine();

        		 int result1 = noOfRoomsBookedInGivenMonth(hotels, month);
        
		if (result1 > 0) 
		{
            			System.out.println(result1);
        		} 
		else 
		{
            			System.out.println("No rooms booked in the given month");
        		}

              	 	Hotel result2 = searchHotelByWifiOption(hotels, wifiOption);
        
		if (result2 != null) 
		{
            			System.out.println(result2.getHotelId());
        		} 
		else 
		{
            			System.out.println("No such option available");
        		}

        		sc.close();
	}
}