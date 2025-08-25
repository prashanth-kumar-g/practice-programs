import java.sql.*;

public class JDBCExampleCrud {
    public static void main(String[] args) {
        try {
            // 1. Load the driver class
            Class.forName("com.mysql.cj.jdbc.Driver");

            // 2. Create a connection
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/studentdb", "mcauser1", "msrit@2024");

            // 3. Create a statement
            Statement stmt = con.createStatement();

            // --- INSERT operation ---
            String insertSQL = "INSERT INTO student (id, name) VALUES (2, 'XYZ')";
            int rowsInserted = stmt.executeUpdate(insertSQL);
            System.out.println("Rows inserted: " + rowsInserted);
 		ResultSet rs = stmt.executeQuery("SELECT * FROM student");
		System.out.println("Current student table data:");
            while (rs.next()) {
                System.out.println(rs.getInt(1) + "  " + rs.getString(2));
            }


            // --- UPDATE operation ---
            String updateSQL = "UPDATE student SET name = 'Ram' WHERE id = 1";
            int rowsUpdated = stmt.executeUpdate(updateSQL);
            System.out.println("Rows updated: " + rowsUpdated);

            // --- DELETE operation ---
            String deleteSQL = "DELETE FROM student WHERE id = 2";
            int rowsDeleted = stmt.executeUpdate(deleteSQL);
            System.out.println("Rows deleted: " + rowsDeleted);

            // 4. Execute query to see updated table data
            ResultSet rs1 = stmt.executeQuery("SELECT * FROM student");

            // 5. Process the result
            System.out.println("Current student table data:");
            while (rs1.next()) {
                System.out.println(rs1.getInt(1) + "  " + rs1.getString(2));
            }

            // 6. Close the connection
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
