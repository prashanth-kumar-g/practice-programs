import java.util.*;

class KYC
{
	private String panCardId;
	private String identityandAddressProofType;
	private String identityandAddressProof;
	private String status;
	
	public KYC(String panCardId, String identityandAddressProofType, String identityandAddressProof, String status)
	{
		this.panCardId = panCardId;
		this.identityandAddressProofType = identityandAddressProofType;
		this.identityandAddressProof = identityandAddressProof;
		this.status = status;
	}
	
	public void setPanCardId(String panCardId)
	{
		this.panCardId = panCardId;
	}
	
	public void setIdentityandAddressProofType(String identityandAddressProofType)
	{
		this.identityandAddressProofType = identityandAddressProofType;
	}
	
	public void setIdentityandAddressProof(String identityandAddressProof)
	{
		this.identityandAddressProof = identityandAddressProof;
	}
	
	public void setStatus(String status)
	{
		this.status = status;
	}
	
	public String getPanCardId()
	{
		return panCardId;
	}
	
	public String getIdentityandAddressProofType()
	{
		return identityandAddressProofType;
	}
	
	public String getIdentityandAddressProof()
	{
		return identityandAddressProof;
	}
	
	public String getStatus()
	{
		return status;
	}
}

class BankAccount
{
	private String accId;
	private String accHolderName;
	private String accType;
	private String occupation;
	private KYC kyc;
	
	public BankAccount(String accId, String accHolderName, String accType, String occupation, KYC kyc)
	{
		this.accId = accId;
		this.accHolderName = accHolderName;
		this.accType = accType;
		this.occupation = occupation;
		this.kyc = kyc;
	}
	
	public void setAccId(String accId)
	{
		this.accId = accId;
	}
	
	public void setAccHolderName(String accHolderName)
	{
		this.accHolderName = accHolderName;
	}
	
	public void setAccType(String accType)
	{
		this.accType = accType;
	}
	
	public void setOccupation(String occupation)
	{
		this.occupation = occupation;
	}
	
	public void setKyc(KYC kyc)
	{
		this.kyc = kyc;
	}
	
	public String getAccId()
	{
		return accId;
	}
	
	public String getAccHolderName()
	{
		return accHolderName;
	}
	
	public String getAccType()
	{
		return accType;
	}
	
	public String getOccupation()
	{
		return occupation;
	}
	
	public KYC getKyc()
	{
		return kyc;
	}
}

public class IPAExamII
{
	public static BankAccount[] fetchBankAccountbyOccupationTypeandStatus(List<BankAccount> banks, String occupationType)
	{
		List<BankAccount> results = new ArrayList<>();
		
		for(BankAccount b : banks)
		{
			if(b.getOccupation().equalsIgnoreCase(occupationType) && b.getKyc().getStatus().equalsIgnoreCase("Lapsed"))
			{
				results.add(b);
			}
		}
		
		if(results.isEmpty())
		{
			return null;
		}
		
		return results.toArray(new BankAccount[0]);
	}
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();	sc.nextLine();
		
		if(n == 0)
		{
			System.out.println("Add more bank accounts, insufficient data");
			return;
		}
		
		List<BankAccount> banks = new ArrayList<>();
		
		for(int i = 0; i < n; i++)
		{
			String accId = sc.nextLine();
			String accHolderName = sc.nextLine();
			String accType = sc.nextLine();
			String occupation = sc.nextLine();
			
			String panCardId = sc.nextLine();
			String identityandAddressProofType = sc.nextLine();
			String identityandAddressProof = sc.nextLine();
			String status = sc.nextLine();
			
			KYC kyc = new KYC(panCardId, identityandAddressProofType, identityandAddressProof, status);
			BankAccount bank = new BankAccount(accId, accHolderName, accType, occupation, kyc);
			
			banks.add(bank);
		}
		
		String occupationType = sc.nextLine();
		
		BankAccount[] results = fetchBankAccountbyOccupationTypeandStatus(banks, occupationType);
		
		if(results == null)
		{
			System.out.println("No bank account with given occupation type and status exists");
		}
		else
		{
			for(BankAccount b : results)
			{
				System.out.println(b.getAccId());
				System.out.println(b.getAccHolderName());
				System.out.println(b.getOccupation());
				System.out.println(b.getKyc().getIdentityandAddressProof());
				System.out.println(b.getKyc().getStatus());
			}
		}
		
		sc.close();
	}
}
