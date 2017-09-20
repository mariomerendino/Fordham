package GUI;
import Logic.*;
import javax.swing.*;
import java.util.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.*;
import java.awt.Color;

public class editClass extends JPanel{
    
    public Checkbox monday = new Checkbox("Monday");
    public Checkbox tuesday = new Checkbox("Tuesday");
    public Checkbox wednesday = new Checkbox("Wednesday");
    public Checkbox thursday = new Checkbox("Thursday");
    public Checkbox friday = new Checkbox("Friday");
   
    /*public static void main(String [] args){
        editClass test = new editClass();
    }*/
   
    public editClass(){
        GridLayout layout = new GridLayout(0,3);
        setLayout(layout);
        setVisible(true);
        setSize(400,200);
        //setResizable(false);
        JLabel nameLabel = new JLabel("Name:");
        JLabel crnLabel = new JLabel("CRN:");
        JLabel sectionLabel = new JLabel("Section:");
        JLabel meetsLabel = new JLabel("Meets:");
        JLabel studentsLabel = new JLabel("Students:");
        JLabel assignmentsLabel = new JLabel("assignmentsLabel:");

        JTextField nameField = new JTextField();
        JTextField crnField = new JTextField();
        JTextField sectionField = new JTextField();

        //JTable testTabel = new JTable();
        add(nameLabel);
        add(nameField);
        add(crnLabel);
        add(crnField);
        add(daysOfTheWeekBar());
        add(Box.createRigidArea(new Dimension(0,0)));
        add(sectionLabel);
        add(sectionField);
    }
    public JPanel daysOfTheWeekBar(){
        JPanel week = new JPanel();
        week.setLayout(new GridLayout(1, 3));
        week.add(monday);
        week.add(tuesday);
        week.add(wednesday);
        week.add(thursday);
        week.add(friday);
        return week;
    }
}