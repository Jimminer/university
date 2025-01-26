import javax.swing.*;

public class MainWindow {
    private static JFrame mainFrame;
    private final static int width = 1000;
    private final static int height = 800;

    MainWindow(){
        DatabaseHandler.connectDatabase();

        mainFrame = new JFrame();

        mainFrame.setTitle("Library Application");
        
        mainFrame.add(Panels.createLoginPanel(mainFrame, width, height));

        mainFrame.setSize(width, height);
        mainFrame.setResizable(false);
        mainFrame.setLayout(null);
        mainFrame.setVisible(true);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        new MainWindow();
    }
}