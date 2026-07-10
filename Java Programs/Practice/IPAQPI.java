import java.util.*;

class Account
{
	private int id;
	private double balance;
	private double interestRate;

	public Account(int id, double balance, double interestRate)
	{
		this.id = id;
		this.balance = balance;
		this.interestRate = interestRate;
	}

	public int getId()
	{
		return id;
	}

	public double getBalance()
	{
		return balance;
	}

	public double getInterestRate()
	{
		return interestRate;
	}

	public void setId(int id)
	{
		this.id = id;
	}

	public void setBalance(double balance)
	{
		this.balance = balance;
	}

	public void setInterestRate(double interestRate)
	{
		this.interestRate = interestRate;
	}
}

public class IPAQPI
{
	public static double calculateInterest(Account account, int noOfYears)
	{
		double percentage = noOfYears * (account.getInterestRate() / 100.0);
		
		double newInterestRate = account.getInterestRate() + percentage;
		
		double interestAmount = account.getBalance() * (newInterestRate / 100.0);
		
		return interestAmount;
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int id = sc.nextInt();
		double balance = sc.nextDouble();
		double interestRate = sc.nextDouble();
		
		int noOfYears = sc.nextInt();
		
		Account account = new Account(id, balance, interestRate);
		
		double result = calculateInterest(account, noOfYears);
		
		System.out.printf("%.3f\n", result);
		
		sc.close();
	}
}
