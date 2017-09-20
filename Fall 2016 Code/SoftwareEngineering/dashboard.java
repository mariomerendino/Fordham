import javax.swing.*;
import java.util.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.*;
public class dashboard extends JFrame{
        public static void main ( String [] args ){
            dashboard frame = new dashboard();
            
        }
        public dashboard(){
            //JButton jbtn = new JButton ("Click Here");
            //add(jbtn);
            //jbtn.setSize(20,10);
            BorderLayout bLayout = new BorderLayout(5,10); //verticalspace, horizontalspace 
            setLayout(bLayout);
            add(createNavigationBar(), BorderLayout.NORTH);
        }
        public JApplet createNavigationBar(){
            
            Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
            Double widthDouble = screenSize.getWidth()/1.7;
            int width = widthDouble.intValue(); 

            JApplet navbar = new JApplet();
            FlowLayout fLayout = new FlowLayout(FlowLayout.LEFT,20,20);
            navbar.setLayout(fLayout);
            setExtendedState(JFrame.MAXIMIZED_BOTH); 
            setVisible(true);
            
            ImageIcon book = new ImageIcon(new ImageIcon("book.png").getImage().getScaledInstance(50, 50, Image.SCALE_DEFAULT));
            JLabel bookIcon = new JLabel(book);
            bookIcon.setSize(50,50);
            navbar.add(bookIcon);

            ImageIcon exclam = new ImageIcon(new ImageIcon("exclam.png").getImage().getScaledInstance(40, 40, Image.SCALE_DEFAULT));
            JLabel exclamIcon = new JLabel(exclam);
            exclamIcon.setSize(40,40);

            ImageIcon plus = new ImageIcon(new ImageIcon("plus.png").getImage().getScaledInstance(40, 40, Image.SCALE_DEFAULT));
            JLabel plusIcon = new JLabel(plus);
            plusIcon.setSize(40,40);
            

            
            JLabel home = new JLabel();
            JLabel students = new JLabel();
            JLabel classes = new JLabel();
            
            Font notBold= new Font("Courier", Font.PLAIN,20);
            Font fontBold = new Font("Courier", Font.BOLD,20);
            
            home.setFont(fontBold);
            home.setText("Home");
            students.setFont(notBold);
            students.setText("Students");
            classes.setFont(notBold);
            classes.setText("Classes");
            
            home.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    home.setFont(fontBold);
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
                }

            });
            students.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    home.setFont(notBold);
                    students.setFont(fontBold);
                    classes.setFont(notBold);
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
                    JOptionPane.showMessageDialog(null, "PlusIcon", "Button Clickeed", JOptionPane.PLAIN_MESSAGE);
                }

            });
            
            navbar.add(home);
            navbar.add(classes);
            navbar.add(students);
            navbar.add(Box.createHorizontalStrut(width));
            navbar.add(plusIcon);
            navbar.add(exclamIcon);
            navbar.setVisible(true); 
            return navbar;
        }
}
