import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.table.*;
import java.awt.event.*;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.awt.Font;

public class Panels {
    private static int lastLoginId = -1;

    public static JPanel createLoginPanel(JFrame frame, int width, int height){
        JPanel panel = new JPanel(null);
        panel.setBounds(0, 0, width, height);

        Font font = new Font("SansSerif", Font.PLAIN, 15);

        JLabel usernameLabel = new JLabel("Username:");
        usernameLabel.setBounds((int)(width*.2), (int)(height*.35), 90, 30);
        usernameLabel.setFont(font);

        JLabel passwordLabel = new JLabel("Password:");
        passwordLabel.setBounds((int)(width*.2), (int)(height*.43), 90, 30);
        passwordLabel.setFont(font);

        JTextField usernameField = new JTextField();
        usernameField.setBounds((int)(width*.2) + 100, (int)(height*.35), (int)(width*.5), 30);
        usernameField.setFont(font);
        
        JPasswordField passwordField = new JPasswordField();
        passwordField.setBounds((int)(width*.2) + 100, (int)(height*.43), (int)(width*.5), 30);
        passwordField.setFont(font);
        

        Action loginButtonAction = new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                int tempId = -1;
                String username = usernameField.getText();
                String password = new String(passwordField.getPassword());

                Boolean found = false;

                ResultSet results = DatabaseHandler.executeQuery("SELECT * FROM users");

                try {
                    while (results.next()) {
                        tempId = results.getInt("id");
                        if (username.equals(results.getString("username")) && password.equals(results.getString("password"))){
                            found = true;
                            break;
                        }
                    }
                }
                catch (SQLException exc){
                    exc.printStackTrace();
                }


                if (!found){
                    JOptionPane.showMessageDialog(frame, "Wrong credentials!", "Error", JOptionPane.ERROR_MESSAGE);
                    return;
                }
                
                lastLoginId = tempId;
                frame.remove(panel);
                frame.revalidate();
                frame.repaint();
                frame.add(createHomePanel(frame, width, height));
            }
        };
        JButton loginButton = new JButton();
        loginButton.setAction(loginButtonAction);
        loginButton.setText("Login");
        loginButton.setBounds((int)(width/2) - 80/2, (int)(height*.5), 80, 30);
        loginButton.setFont(font);
        loginButton.getInputMap(JComponent.WHEN_IN_FOCUSED_WINDOW).put(KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, 0), "loginButtonPressed");
        loginButton.getActionMap().put("loginButtonPressed", loginButtonAction);

        panel.add(passwordField);
        panel.add(usernameLabel);
        panel.add(passwordLabel);
        panel.add(loginButton);
        panel.add(usernameField);

        return panel;
    }



    public static JPanel createHomePanel(JFrame frame, int width, int height){
        JPanel panel = new JPanel(null);
        panel.setBounds(0, 0, width, height);

        Font font = new Font("SansSerif", Font.PLAIN, 15);
        
        JButton browseButton = new JButton("Browse Books");
        browseButton.setBounds((int)(width*.2), (int)(height/2) - 30/2, 150, 30);
        browseButton.setFont(font);
        browseButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                frame.remove(panel);
                frame.revalidate();
                frame.repaint();
                frame.add(createBrowsePanel(frame, width, height));
            }
        });

        JButton myBrowseButton = new JButton("My Books");
        myBrowseButton.setBounds((int)(width*.4), (int)(height/2) - 30/2, 150, 30);
        myBrowseButton.setFont(font);
        myBrowseButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                frame.remove(panel);
                frame.revalidate();
                frame.repaint();
                frame.add(createMyBrowsePanel(frame, width, height));
            }
        });

        JButton logoutButton = new JButton("Logout");
        logoutButton.setBounds((int)(width*.6), (int)(height/2) - 30/2, 150, 30);
        logoutButton.setFont(font);
        logoutButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                lastLoginId = -1;

                frame.remove(panel);
                frame.revalidate();
                frame.repaint();
                frame.add(createLoginPanel(frame, width, height));
            }
        });

        panel.add(browseButton);
        panel.add(myBrowseButton);
        panel.add(logoutButton);

        return panel;
    }



    public static JPanel createBrowsePanel(JFrame frame, int width, int height){
        JPanel panel = new JPanel(null);
        panel.setBounds(0, 0, width, height);

        Font font = new Font("SansSerif", Font.PLAIN, 15);

        JLabel searchLabel = new JLabel("Search:");
        searchLabel.setBounds(20, 20, 60, 30);
        searchLabel.setFont(font);

        JTextField searchField = new JTextField();
        searchField.setBounds(90, 20, (int)(width*.6) - 70, 30);
        searchField.setFont(new Font("SansSerif", Font.PLAIN, 13));

        

        JButton backButton = new JButton("Back");
        backButton.setBounds((int)(width*.9), 20, 80, 30);
        backButton.setFont(font);
        backButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                frame.remove(panel);
                frame.revalidate();
                frame.repaint();
                frame.add(createHomePanel(frame, width, height));
            }
        });
        
        String columns[]={"ISBN", "Title", "Description", "Authors"};
        JTable table = new JTable(){
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };
        DefaultTableModel tableModel = new DefaultTableModel(0, 0);
        tableModel.setColumnIdentifiers(columns);
        table.setModel(tableModel);
        table.setFont(font);
        table.setRowHeight(25);
        table.getColumnModel().getColumn(0).setMinWidth(50);
        table.getColumnModel().getColumn(0).setMaxWidth(50);
        table.getColumnModel().getColumn(1).setMinWidth(200);
        table.getColumnModel().getColumn(1).setMaxWidth(200);
        table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

        ResultSet results = DatabaseHandler.executeQuery("SELECT * FROM books ORDER BY title");

        try {
            while (results.next()) {
                String authorString = new String();

                ResultSet authors = DatabaseHandler.executeQuery("SELECT firstName, lastName FROM authors " +
                                                                 "WHERE id IN ( " +
                                                                 "  SELECT authorId FROM bookAuthors WHERE isbn = " + results.getString("isbn") +
                                                                 ")"
                );

                while(authors.next()) {
                    authorString += authors.getString("firstName") + " " + authors.getString("lastName") + " | ";
                }

                if (authorString != null && authorString.length() > 0){
                    authorString = authorString.substring(0, authorString.length() - 3);
                }

                tableModel.addRow(new Object[] {results.getString("isbn"), results.getString("title"), results.getString("description"), authorString});
            }

            table.doLayout();
        }
        catch (SQLException exc){
            exc.printStackTrace();
        }

        searchField.getDocument().addDocumentListener(new DocumentListener() {
            public void changedUpdate(DocumentEvent e) {
                update();
            }

            public void removeUpdate(DocumentEvent e) {
                update();
            }

            public void insertUpdate(DocumentEvent e) {
                update();
            }

            public void update(){
                tableModel.setRowCount(0);

                ResultSet results = DatabaseHandler.executeQuery("SELECT * FROM books " + 
                                                                 "WHERE title LIKE '%" + searchField.getText() + "%' " +
                                                                 "OR isbn IN ( " +
                                                                 "  SELECT isbn FROM bookAuthors WHERE authorId IN ( "+
                                                                 "    SELECT id FROM authors WHERE (firstName LIKE '%" + searchField.getText() + "%' OR lastName LIKE '%" + searchField.getText() + "%') " +
                                                                 "  ) " +
                                                                 ") ORDER BY title"
                );

                try {
                    
                    while (results.next()) {
                        String authorString = new String();
    
                        ResultSet authors = DatabaseHandler.executeQuery("SELECT firstName, lastName FROM authors " +
                                                                        "WHERE id IN ( " +
                                                                        "  SELECT authorId FROM bookAuthors WHERE isbn = " + results.getString("isbn") +
                                                                        ")"
                        );
    
                        while(authors.next()) {
                            authorString += authors.getString("firstName") + " " + authors.getString("lastName") + " | ";
                        }
        
                        if (authorString != null && authorString.length() > 0){
                            authorString = authorString.substring(0, authorString.length() - 3);
                        }

                        tableModel.addRow(new Object[] {results.getString("isbn"), results.getString("title"), results.getString("description"), authorString});
                    }
                    table.doLayout();
                }
                catch (SQLException exc){
                    exc.printStackTrace();
                }
            }
        });
        
        JButton reserveButton = new JButton("Reserve Selected");
        reserveButton.setBounds((int)(width*.65), 20, 200, 30);
        reserveButton.setFont(font);
        reserveButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                Object[] rowData = new Object[table.getColumnCount()];

                for (int column = 0; column < table.getColumnCount(); column++) {
                    rowData[column] = table.getValueAt(table.getSelectedRow(), column);
                }

                ResultSet results = DatabaseHandler.executeQuery("SELECT * FROM bookReservations WHERE timeReserved >= DATE_SUB(NOW(), INTERVAL 30 DAY) AND isbn = " + rowData[0]);

                try {
                    while (results.next()) {
                        JOptionPane.showMessageDialog(frame, "Book already reserved! Please choose a different one.", "Error", JOptionPane.ERROR_MESSAGE);
                        return;
                    }

                    DatabaseHandler.executeQuery("INSERT INTO bookReservations VALUES( " + rowData[0] + ", " + lastLoginId + ", NOW())");
                    JOptionPane.showMessageDialog(frame, "Book reserved.");
                }
                catch (SQLException exc){
                    exc.printStackTrace();
                }
            }
        });
        
        JScrollPane scrollPane = new JScrollPane(table);
        scrollPane.setBounds(0, 60, width, height - 60);


        panel.add(searchLabel);
        panel.add(searchField);
        panel.add(reserveButton);
        panel.add(backButton);
        panel.add(scrollPane);

        return panel;
    }

    public static JPanel createMyBrowsePanel(JFrame frame, int width, int height){
        JPanel panel = new JPanel(null);
        panel.setBounds(0, 0, width, height);

        Font font = new Font("SansSerif", Font.PLAIN, 15);

        JLabel reservedBooksLabel = new JLabel("Reserved Books:");
        reservedBooksLabel.setBounds((int)(width/2) - 200/2, 20, 200, 30);
        reservedBooksLabel.setFont(font);

        JButton backButton = new JButton("Back");
        backButton.setBounds((int)(width*.9), 20, 80, 30);
        backButton.setFont(font);
        backButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                frame.remove(panel);
                frame.revalidate();
                frame.repaint();
                frame.add(createHomePanel(frame, width, height));
            }
        });
        
        String columns[]={"ISBN", "Title", "Description", "Time of Reservation"};
        JTable table = new JTable(){
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };
        DefaultTableModel tableModel = new DefaultTableModel(0, 0);
        tableModel.setColumnIdentifiers(columns);
        table.setModel(tableModel);
        table.setFont(font);
        table.setRowHeight(25);
        table.getColumnModel().getColumn(0).setMinWidth(50);
        table.getColumnModel().getColumn(0).setMaxWidth(50);
        table.getColumnModel().getColumn(1).setMinWidth(200);
        table.getColumnModel().getColumn(1).setMaxWidth(200);
        table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

        ResultSet results = DatabaseHandler.executeQuery("SELECT books.isbn, title, description, timeReserved FROM books, bookReservations WHERE books.isbn = bookReservations.isbn AND bookReservations.userId = " + lastLoginId + " ORDER BY timeReserved DESC");

        try {
            while (results.next()) {

                tableModel.addRow(new Object[] {results.getString("isbn"), results.getString("title"), results.getString("description"), results.getString("timeReserved")});
            }

            table.doLayout();
        }
        catch (SQLException exc){
            exc.printStackTrace();
        }
        
        JScrollPane scrollPane = new JScrollPane(table);
        scrollPane.setBounds(0, 60, width, height - 60);


        panel.add(reservedBooksLabel);
        panel.add(backButton);
        panel.add(scrollPane);

        return panel;
    }
}
