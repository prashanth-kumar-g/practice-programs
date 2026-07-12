import java.util.*;

class Spotify
{
	private int spotifyId;
	private String profileName;
	private String subscriptionType;
	private double subscriptionPrice;
	private String groupSessionAvailable;

	public Spotify(int spotifyId, String profileName, String subscriptionType, double subscriptionPrice, String groupSessionAvailable)
	{
		this.spotifyId = spotifyId;
		this.profileName = profileName;
		this.subscriptionType = subscriptionType;
		this.subscriptionPrice = subscriptionPrice;
		this.groupSessionAvailable = groupSessionAvailable;
	}

	public int getSpotifyId()
	{
		return spotifyId;
	}

	public String getProfileName()
	{
		return profileName;
	}

	public String getSubscriptionType()
	{
		return subscriptionType;
	}

	public double getSubscriptionPrice()
	{
		return subscriptionPrice;
	}

	public String getGroupSessionAvailable()
	{
		return groupSessionAvailable;
	}

	public void setSpotifyId(int spotifyId)
	{
		this.spotifyId = spotifyId;
	}

	public void setProfileName(String profileName)
	{
		this.profileName = profileName;
	}

	public void setSubscriptionType(String subscriptionType)
	{
		this.subscriptionType = subscriptionType;
	}

	public void setSubscriptionPrice(double subscriptionPrice)
	{
		this.subscriptionPrice = subscriptionPrice;
	}

	public void setGroupSessionAvailable(String groupSessionAvailable)
	{
		this.groupSessionAvailable = groupSessionAvailable;
	}
}

public class IpaDemo
{
	public static double findAvgSpotifySubsByType(Spotify[] spotifys, String subscriptionType, String groupSessionAvailable)
	{
		double sum = 0;
		int count = 0;
		
		for (Spotify s : spotifys)
		{
			if (s.getSubscriptionType().equalsIgnoreCase(subscriptionType) && s.getGroupSessionAvailable().equalsIgnoreCase(groupSessionAvailable))
			{
				sum = sum + s.getSubscriptionPrice();
				count++;
			}
		}
		
		if (count == 0)
		{
			return 0.0;
		}
		
		return sum / count;
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		Spotify[] spotifys = new Spotify[4];
		
		for (int i = 0; i < 4; i++)
		{
			int spotifyId = sc.nextInt();
			sc.nextLine();
			
			String profileName = sc.nextLine();
			
			String subscriptionType = sc.nextLine();
			
			double subscriptionPrice = sc.nextDouble();
			sc.nextLine();
			
			String groupSessionAvailable = sc.nextLine();
			
			spotifys[i] = new Spotify(spotifyId, profileName, subscriptionType, subscriptionPrice, groupSessionAvailable);
		}
		
		String searchSubscriptionType = sc.nextLine();
		String searchGroupSessionAvailable = sc.nextLine();
		
		double result = findAvgSpotifySubsByType(spotifys, searchSubscriptionType, searchGroupSessionAvailable);
		
		if (result > 0)
		{
			System.out.println(result);
		}
		else
		{
			System.out.println("There are no such Spotify Subscription");
		}
		
		sc.close();
	}
}
