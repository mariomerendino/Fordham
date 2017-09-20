package GUI;
import Logic.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;
import java.util.*;

public class DataFileTable2 extends JPanel {
    public DataFileTable2() {
        JTable table;
        DataFileTableModel2 model;
        Font f;
         
        f = new Font("SanSerif",Font.PLAIN,24);
        setFont(f);
        setLayout(new BorderLayout());
         
        model = new DataFileTableModel2(System.getProperty("user.dir") + "/data/Mario/master_student_list.csv");
        table = new JTable();
        table.setModel(model);
        table.createDefaultColumnsFromModel();
         
        JScrollPane scrollpane = new JScrollPane(table);
        add(scrollpane);
        setVisible(true);
        
    }

    public void display( ) {
        JFrame frame = new JFrame("Data File Table");
        DataFileTable2 panel;
         
        panel = new DataFileTable2();
    
        frame.setForeground(Color.black);
        frame.setBackground(Color.lightGray);
        frame.getContentPane().add(panel,"Center");
         
        frame.setSize(panel.getPreferredSize());
        frame.setVisible(true);
	    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

   }
}
