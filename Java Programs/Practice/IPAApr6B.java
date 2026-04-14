import java.util.*;

class Author 
{
    private int authorId;
    private String authorName;

    public Author(int authorId, String authorName) 
	{
        this.authorId = authorId;
        this.authorName = authorName;
    }

    public int getAuthorId() 
	{
        return authorId;
    }

    public String getAuthorName() 
	{
        return authorName;
    }

    public void setAuthorId(int authorId) 
	{
        this.authorId = authorId;
    }

    public void setAuthorName(String authorName) 
	{
        this.authorName = authorName;
    }
}

class Book 
{
    private int bookId;
    private String title;
    private String genre;
    private double price;
    private Author author;

    public Book(int bookId, String title, String genre, double price, Author author) 
	{
        this.bookId = bookId;
        this.title = title;
        this.genre = genre;
        this.price = price;
        this.author = author;
    }

    public int getBookId() 
	{
        return bookId;
    }

    public String getTitle() 
	{
        return title;
    }

    public String getGenre() 
	{
        return genre;
    }

    public double getPrice() 
	{
        return price;
    }

    public Author getAuthor() 
	{
        return author;
    }

    public void setBookId(int bookId) 
	{
        this.bookId = bookId;
    }

    public void setTitle(String title) 
	{
        this.title = title;
    }

    public void setGenre(String genre) 
	{
        this.genre = genre;
    }

    public void setPrice(double price) 
	{
        this.price = price;
    }

    public void setAuthor(Author author) 
	{
        this.author = author;
    }
}

class Business 
{
    public static List<Book> getBooksBelongingToAGenre(List<Book> books, String genre) 
	{
        List<Book> result = new ArrayList<>();

        for (Book b : books) 
		{
            if (b.getGenre().equalsIgnoreCase(genre)) 
			{
                result.add(b);
            }
        }

        return result;
    }

    public static List<Book> calculateDiscountedPrice(List<Book> books, String genre, double discount) 
	{
        List<Book> result = new ArrayList<>();

        for (Book b : books) 
		{
            if (b.getGenre().equalsIgnoreCase(genre)) 
			{
                double discountedPrice = b.getPrice() - (b.getPrice() * discount / 100.0);
                b.setPrice(discountedPrice);
                result.add(b);
            }
        }

        return result;
    }
}

public class IPAApr6A 
{
    public static void main(String[] args) 
	{
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        List<Book> books = new ArrayList<>();

        for (int i = 0; i < n; i++) 
		{
            int authorId = sc.nextInt();
<<<<<<< HEAD
            sc.nextLine();
            String authorName = sc.nextLine();

            int bookId = sc.nextInt();
            sc.nextLine();
=======
            sc.nextLine();
            String authorName = sc.nextLine();

            int bookId = sc.nextInt();
            sc.nextLine();
>>>>>>> fea6b13111be2ac59cf30cb06ea3aa4b264f277c
            String title = sc.nextLine();
            String genre = sc.nextLine();
            double price = sc.nextDouble();
            sc.nextLine();

            Author author = new Author(authorId, authorName);
            Book book = new Book(bookId, title, genre, price, author);
            books.add(book);
        }

        String genre1 = sc.nextLine();
        String genre2 = sc.nextLine();
        double discount = Double.parseDouble(sc.nextLine().trim());

        List<Book> genreBooks = Business.getBooksBelongingToAGenre(books, genre1);

        if (genreBooks.isEmpty()) 
		{
            System.out.println("Genre is not available in the list");
        } 
		else 
		{
            for (Book b : genreBooks) 
			{
                System.out.println("AuthorName: " + b.getAuthor().getAuthorName() + ", Title: " + b.getTitle());
            }
        }

        System.out.println();

        List<Book> discountedBooks = Business.calculateDiscountedPrice(books, genre2, discount);

        if (discountedBooks.isEmpty()) 
		{
            System.out.println("Discounted books are unavailable in the given genre");
        } 
		else 
		{
            System.out.println("Discounted " + genre2 + " Books:");
            
			for (Book b : discountedBooks) 
			{
                System.out.println("AuthorName: " + b.getAuthor().getAuthorName() + ", Title: " + b.getTitle() + ", Updated Price: " + b.getPrice());
            }
        }

        sc.close();
    }
}
