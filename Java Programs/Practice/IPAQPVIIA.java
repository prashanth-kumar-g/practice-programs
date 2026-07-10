import java.util.*;

class Document
{
	private int id;
	private String title;
	private String folderName;
	private int pages;

	public Document(int id, String title, String folderName, int pages)
	{
		this.id = id;
		this.title = title;
		this.folderName = folderName;
		this.pages = pages;
	}

	public int getId()
	{
		return id;
	}

	public String getTitle()
	{
		return title;
	}

	public String getFolderName()
	{
		return folderName;
	}

	public int getPages()
	{
		return pages;
	}

	public void setId(int id)
	{
		this.id = id;
	}

	public void setTitle(String title)
	{
		this.title = title;
	}

	public void setFolderName(String folderName)
	{
		this.folderName = folderName;
	}

	public void setPages(int pages)
	{
		this.pages = pages;
	}
}

public class IPAQPVIIA
{
	public static Document[] docsWithOddPages(Document[] docs)
	{
		List<Document> list = new ArrayList<>();
		
		for (Document doc : docs)
		{
			if (doc.getPages() % 2 != 0)
			{
				list.add(doc);
			}
		}
		
		if (list.isEmpty())
		{
			return null;
		}
		
		list.sort((a, b) -> a.getId() - b.getId());
		
		return list.toArray(new Document[0]);
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		Document[] docs = new Document[4];
		
		for (int i = 0; i < 4; i++)
		{
			int id = sc.nextInt();
			sc.nextLine();
			
			String title = sc.nextLine();
			
			String folderName = sc.nextLine();
			
			int pages = sc.nextInt();
			if (sc.hasNextLine())
			{
				sc.nextLine();
			}
			
			docs[i] = new Document(id, title, folderName, pages);
		}
		
		Document[] result = docsWithOddPages(docs);
		
		if (result != null)
		{
			for (Document doc : result)
			{
				System.out.println(doc.getId() + " " + doc.getTitle() + " " + doc.getFolderName() + " " + doc.getPages());
			}
		}
		
		sc.close();
	}
}
