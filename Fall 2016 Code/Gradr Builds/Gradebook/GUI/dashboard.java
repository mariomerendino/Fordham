package GUI;
import Logic.*;
import javax.swing.*;
import java.util.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.*;
import java.awt.Color;

public class dashboard extends JFrame{
        /*public static void main ( String [] args ){
            dashboard frame = new dashboard();
            
        }*/
        //Constructor for the dashboard
        public dashboard(){
            
            //sets the BorderLayout for the jframe. 
            BorderLayout bLayout = new BorderLayout(5,10); //verticalspace, horizontalspace 
            setLayout(bLayout);
            //Sets the size of the the entire dashboard frame. 
            setExtendedState(JFrame.MAXIMIZED_BOTH); 
            setVisible(true);
            //adds a navigation to the top of the page. 
            add(createNavigationBar(), BorderLayout.NORTH);
            add(homePage(), BorderLayout.CENTER);
        }
        //Creates a Java Applet for the navigation bar at the top. 
        public JApplet createNavigationBar(){
            
            //Creates JApplet(Container) to eventually be returned
            JApplet navbar = new JApplet();
            navbar.getContentPane().setBackground(Color.GRAY);
            //gets Screen Size, used later...
            Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
            Double widthDouble = screenSize.getWidth()/1.7;
            int width = widthDouble.intValue(); 

            //Sets up the flowlayout for the nav bar. 
            FlowLayout fLayout = new FlowLayout(FlowLayout.LEFT,20,20);
            navbar.setLayout(fLayout);
        
            //Adds icon for the book.
            ImageIcon book = new ImageIcon(new ImageIcon(System.getProperty("user.dir") +"/GUI/book.png").getImage().getScaledInstance(50, 50, Image.SCALE_DEFAULT));
            JLabel bookIcon = new JLabel(book);
            bookIcon.setSize(50,50);
            navbar.add(bookIcon);

            //Adds the exclamation point button icon. 
            ImageIcon exclam = new ImageIcon(new ImageIcon(System.getProperty("user.dir") +"/GUI/exclam.png").getImage().getScaledInstance(40, 40, Image.SCALE_DEFAULT));
            JLabel exclamIcon = new JLabel(exclam);
            exclamIcon.setSize(40,40);

            //Adds the exclamation point button icon.
            ImageIcon plus = new ImageIcon(new ImageIcon(System.getProperty("user.dir") +"/GUI/plus.png").getImage().getScaledInstance(40, 40, Image.SCALE_DEFAULT));
            JLabel plusIcon = new JLabel(plus);
            plusIcon.setSize(40,40);
            
            //Creates Labels for home, students, and classes. 
            JLabel home = new JLabel();
            JLabel students = new JLabel();
            JLabel classes = new JLabel();
            
            //Creates two new fonts one bold and the other not.
            Font notBold= new Font("Courier", Font.PLAIN,20);
            Font fontBold = new Font("Courier", Font.BOLD,20);
            
            //Sets the text and default bolding of each jlabel.
            home.setFont(fontBold);
            home.setText("Home");
            students.setFont(notBold);
            students.setText("Students");
            classes.setFont(notBold);
            classes.setText("Classes");
            
            //adds listeners for clicks on the Home, classes, studens, plus, and ExcalmationPoint
            home.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    home.setFont(fontBold);
                    //swaps the center so it displays the homepage. 
                    swapCenter(homePage());
                    students.setFont(notBold);
                    classes.setFont(notBold);
                }

            });
            classes.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    home.setFont(notBold);
                    students.setFont(notBold);
                    classes.setFont(fontBold);
                    swapCenter(new editClass());
                }

            });
            students.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    home.setFont(notBold);
                    students.setFont(fontBold);
                    classes.setFont(notBold);
                    swapCenter(new DataFileTable2());
                }

            });
            exclamIcon.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    JOptionPane.showMessageDialog(null, "ExcalmationPoint", "Button Clickeed", JOptionPane.PLAIN_MESSAGE);
                }

            });
            plusIcon.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    home.setFont(fontBold); 
                    swapCenter(homePage());
                    students.setFont(notBold);
                    classes.setFont(notBold);
                    addButtonPage test = new addButtonPage();
                    
                }

            });
            //adds the labels to the applet. 
            
            navbar.add(home);
            navbar.add(classes);
            navbar.add(students);

            //creates a horizontalspace
            navbar.add(Box.createHorizontalStrut(width));

            //finally adds the last buttons to the applet. 
            navbar.add(plusIcon);
            navbar.add(exclamIcon);
            navbar.setVisible(true); 
            return navbar;
        }
        //public JTable returnClassList(String className){

        //}
        public JPanel homePage(){
            JPanel page = new JPanel();
            String name = new String("Mario");
            JLabel welcome = new JLabel();
            Font welcomeFont= new Font("Stencil", Font.PLAIN, 40);
            welcome.setText("Welcome, " + name);
            welcome.setFont(welcomeFont);
            welcome.setVisible(true);
            page.add(welcome);
            return page;
        }
        public void swapCenter(JPanel jp){
            JPanel blank = new JPanel();
            add(blank, BorderLayout.CENTER);
            add(jp, BorderLayout.CENTER);
            revalidate();
        }
}
