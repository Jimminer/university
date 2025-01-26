import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DatabaseHandler {
    private static final String domain = "192.168.1.***";
    private static final int port = 3306;
    private static final String username = "*****";
    private static final String password = "****";
    private static final String database = "library";
    private static final String implementation = "mariadb";

    private static final String url = "jdbc:" + implementation + "://" + domain + ":" + port + "/" + database;
    private static final String mariaDbDriver = "org.mariadb.jdbc.Driver";
    private static final String mySqlDriver = "com.mysql.cj.jdbc.Driver";

    private static Connection connection;

    public static void connectDatabase(){
        try {
            if (implementation.equals("mariadb")){
                Class.forName(mariaDbDriver);
            }
            else if (implementation.equals("mysql")){
                Class.forName(mySqlDriver);
            }
            else{
                System.out.println("SQL Implementation not supported!");
                System.exit(1);
            }

            connection = DriverManager.getConnection(url, username, password);
        }
        catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static ResultSet executeQuery(String query){
        try {
            Statement statement = connection.createStatement();

            ResultSet results = statement.executeQuery(query);

            statement.close();

            return results;
        }
        catch (SQLException e) {
            e.printStackTrace();
        }

        return null;
    }

    public static void closeConnection(){
        try {
            connection.close();
        }
        catch (SQLException e) {
            e.printStackTrace();
        }
    }
}