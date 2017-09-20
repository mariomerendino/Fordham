package GUI;
import Logic.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.util.List;
import java.awt.event.*;

public class addClassPage extends JFrame{

    public JTextField nameField = new JTextField();

    public static void main(String [] args){
        addClassPage page = new addClassPage();
    }
    public addClassPage(){
        String prompt = new String("New Class");
        JLabel promptLabel = new JLabel();
        Font promptFont= new Font("Stencil", Font.PLAIN, 32);
        Font labelFont= new Font("Stencil", Font.PLAIN, 20);
        promptLabel.setText(prompt);
        promptLabel.setFont(promptFont);
        
        JLabel nameLabel = new JLabel("Name:");
        JLabel semesterLabel = new JLabel("Semester:");
        JLabel crnLabel = new JLabel("CRN:");
        JComboBox dropDown = createDropDown();

        nameLabel.setFont(labelFont);
        semesterLabel.setFont(labelFont);
        crnLabel.setFont(labelFont);

        JButton saveButton = new JButton("Save");
        JButton cancelButton = new JButton("Cancel");

        JTextField nameField = new JTextField();
        JTextField crnField = new JTextField(3);

        setResizable(false);
        setVisible(true);
        setSize(1000,250);
        GridLayout layout = new GridLayout(0,3);
        setLayout(layout);
        
        add(Box.createRigidArea(new Dimension(0,0)));
        add(promptLabel);
        add(Box.createRigidArea(new Dimension(0,0)));
        
        add(nameLabel);
        add(nameField);
        add(saveButton);
        

        add(crnLabel);
        add(crnField);
        add(cancelButton);

        add(semesterLabel);
        add(dropDown);
        add(Box.createRigidArea(new Dimension(0,0)));
        

        saveButton.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    FileIO addClass = new FileIO();
                    String semester = (String)dropDown.getSelectedItem();
                    String name = nameField.getText();
                    String crn = crnField.getText();
                    
                    dispose();
                }
            });
        cancelButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });
    }
    public JComboBox createDropDown(){
        FileIO io = new FileIO();
        String[] semesterArray = new String[2];
        semesterArray[0] = "Fall";
        semesterArray[1] = "Spring";
        JComboBox box = new JComboBox(semesterArray);
        return box;
    }
}