import java.util.*;

class Book
{
	private int id;
	private String title;
	private String author;
	private double price;

	public Book(int id, String title, String author, double price)
	{
		this.id = id;
		this.title = title;
		this.author = author;
		this.price = price;
	}

	public int getId()
	{
		return id;
	}

	public String getTitle()
	{
		return title;
	}

	public String getAuthor()
	{
		return author;
	}

	public double getPrice()
	{
		return price;
	}

	public void setId(int id)
	{
		this.id = id;
	}

	public void setTitle(String title)
	{
		this.title = title;
	}

	public void setAuthor(String author)
	{
		this.author = author;
	}

	public void setPrice(double price)
	{
		this.price = price;
	}
}

public class IPAQPVIIb
{
	public static Book[] sortBooksByPrice(Book[] books)
	{
		List<Book> list = new ArrayList<>(Arrays.asList(books));
		
		list.sort((a, b) -> Double.compare(a.getPrice(), b.getPrice()));
		
		return list.toArray(new Book[0]);
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		Book[] books = new Book[4];
		
		for (int i = 0; i < 4; i++)
		{
			int id = sc.nextInt();
			sc.nextLine();
			
			String title = sc.nextLine();
			
			String author = sc.nextLine();
			
			double price = sc.nextDouble();
			if (sc.hasNextLine())
			{
				sc.nextLine();
			}
			
			books[i] = new Book(id, title, author, price);
		}
		
		Book[] result = sortBooksByPrice(books);
		
		if (result != null)
		{
			for (Book book : result)
			{
				System.out.println(book.getId() + " " + book.getTitle() + " " + book.getAuthor() + " " + book.getPrice());
			}
		}
		
		sc.close();
	}
}
