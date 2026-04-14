import java.util.*;

// Student class
class Student 
{
    private int id;
    private String name;
    private int totalMarksObt;

    // Constructor
    public Student(int id, String name, int totalMarksObt) 
	{
        this.id = id;
        this.name = name;
        this.totalMarksObt = totalMarksObt;
    }

    // Getters
    public int getId() 
	{ 
		return id; 
	}
    
	public String getName() 
	{ 
		return name; 
	}
    
	public int getTotalMarksObt() 
	{ 
		return totalMarksObt; 
	}

    // Setters
    public void setId(int id) 
	{ 
		this.id = id; 
	}
    
	public void setName(String name) 
	{ 
		this.name = name; 
	}
    
	public void setTotalMarksObt(int totalMarksObt) 
	{ 
		this.totalMarksObt = totalMarksObt; 
	}
}

// Solution class
public class IPAApr6B 
{
    // Method 1: Find student with highest total
    public static String findStudentWithHighestTotal(Student[] students) 
	{
        int max = Integer.MIN_VALUE;
        String result = "";

        for (Student s : students) 
		{
            if (s.getTotalMarksObt() > max) 
			{
                max = s.getTotalMarksObt();
                result = s.getName();
            }
        }
<<<<<<< HEAD

        return result.toUpperCase(); // required in uppercase
    }

    // Method 2: Search students by percentage >= 70
    public static int[] searchStudentsByPercentage(Student[] students) 
	{
        List<Integer> list = new ArrayList<>();

=======

        return result.toUpperCase(); // required in uppercase
    }

    // Method 2: Search students by percentage >= 70
    public static int[] searchStudentsByPercentage(Student[] students) 
	{
        List<Integer> list = new ArrayList<>();

>>>>>>> fea6b13111be2ac59cf30cb06ea3aa4b264f277c
        for (Student s : students) 
		{
            // total marks out of 400
            double percentage = (s.getTotalMarksObt() / 400.0) * 100;

            if (percentage >= 70) 
			{
                list.add(s.getId());
            }
        }

        if (list.isEmpty()) 
		{
            return null;
        }

        // sort ascending
        Collections.sort(list);

        // convert to array
        int[] result = new int[list.size()];
        for (int i = 0; i < list.size(); i++) 
		{
            result[i] = list.get(i);
        }

        return result;
    }

    // Main method
    public static void main(String[] args) 
	{
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
		
        Student[] students = new Student[n];

        for (int i = 0; i < n; i++) 
		{
            int id = sc.nextInt();
            sc.nextLine();
            String name = sc.nextLine();
            int marks = sc.nextInt();
            sc.nextLine();

            students[i] = new Student(id, name, marks);
        }

        // Method 1
        String highest = findStudentWithHighestTotal(students);
        System.out.println(highest);

        // Method 2
        int[] result = searchStudentsByPercentage(students);

        if (result != null) 
		{
            for (int id : result) 
			{
                System.out.println(id);
            }
        } 
		else 
		{
            System.out.println("No Student found with mentioned attribute");
        }

        sc.close();
    }
}
