enum WeekDay
{
	SUNDAY(false),
	MONDAY(true),
	TUESDAY(true),
	WEDNESDAY(true),
	THURSDAY(true),
	FRIDAY(true),
	SATURDAY(false);

	private boolean isWorkingDay;

	WeekDay(boolean isWorkingDay)
	{
		this.isWorkingDay = isWorkingDay;
	}

	boolean getIsWorkingDay()
	{
		return isWorkingDay;
	}
}

public class EnumDemo
{
	public static void main(String [] args)
	{
		WeekDay week = WeekDay.valueOf("WEDNESDAY");

		System.out.println("\n Selected Day : " + week + ", Is Working Day : " + week.getIsWorkingDay());

		System.out.printf("\n %-9s %-17s %-14s \n", "Ordinal", "Day of the Week", "Is Working Day");
		System.out.println("\n------------------------------------------------");


		for( WeekDay w : WeekDay.values() )
		{
			System.out.printf("\n %-9d %-17s %-14s \n", w.ordinal(), w, w.getIsWorkingDay());
		}

		System.out.println();
	}
}

