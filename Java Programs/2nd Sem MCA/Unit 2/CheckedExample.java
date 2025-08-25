import java.io.*;

public class CheckedExample {
    public static void main(String[] args) {
        try {
           
   FileReader file = new FileReader("myfile.txt");
            int data = file.read(); 
            System.out.println("First character: " + (char)data);
            file.close();
        } 
        catch (FileNotFoundException e) {
            System.out.println("File not found.");
        } 
        catch (IOException e) {
            System.out.println("Error reading the file.");
        }
    }
}
