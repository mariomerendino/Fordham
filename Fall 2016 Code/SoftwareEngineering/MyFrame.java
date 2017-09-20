import javax.swing.*;
import java.util.*;
import java.awt.*;
public class MyFrame extends JFrame{
        public static void main ( String [] args ){
            MyFrame frame = new MyFrame();
            
            
        }
        public MyFrame(){
            //JButton jbtn = new JButton ("Click Here");
            //add(jbtn);
            //jbtn.setSize(20,10);
            BorderLayout bLayout = new BorderLayout(5,10); //verticalspace, horizontalspace 
            FlowLayout fLayout = new FlowLayout(FlowLayout.LEFT,10,20); //
            GridLayout gLayout = new GridLayout(3,2,5,5); //numRows, numCols, verticalSpace, HorizontalSpace
            setLayout(gLayout);
            add(new JLabel("FirstName"));
            add(new JTextField(8));
            add(new JLabel("Mi"));
            add(new JTextField(1));
            add(new JLabel("LastName"));
            add(new JTextField(8));
            setSize(400,300);// setLocation(), setLocationRelativeTo(), setDefaultCloseOperation(), 
            setVisible(true);
        }

}