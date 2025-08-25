import java.sql.*;

public class JDBCExample {
    public static void main(String[] args) {
        try {
            // 1. Load the driver class
            Class.forName("com.mysql.cj.jdbc.Driver");

            // 2. Create a connection
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/studentdb", "mcauser1", "msrit@2024");

            // 3. Create a statement
            Statement stmt = con.createStatement();

            // 4. Execute query
            ResultSet rs = stmt.executeQuery("SELECT * FROM student");

            // 5. Process the result
            while (rs.next()) {
                System.out.println(rs.getInt(1) + "  " + rs.getString(2));
            }

            // 6. Close the connection
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
