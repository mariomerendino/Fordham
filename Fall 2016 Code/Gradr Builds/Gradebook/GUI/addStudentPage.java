package GUI;
import Logic.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.util.List;
import java.awt.event.*;

public class addStudentPage extends JFrame{

    public JTextField nameField = new JTextField();
    public JTextField ageField = new JTextField();
    public JTextField idField = new JTextField();
    public JComboBox dropDown = createDropDown();

    public static void main(String [] args){
        addStudentPage page = new addStudentPage();
    }
    public addStudentPage(){
        String prompt = new String("New Student");
        JLabel promptLabel = new JLabel();
        Font promptFont= new Font("Stencil", Font.PLAIN, 32);
        Font labelFont= new Font("Stencil", Font.PLAIN, 20);
        promptLabel.setText(prompt);
        promptLabel.setFont(promptFont);
        
        JLabel nameLabel = new JLabel("Name:");
        JLabel classLabel = new JLabel("Class:");
        JLabel ageLabel = new JLabel("Age:");
        JLabel idLabel = new JLabel("Student Id:");

        nameLabel.setFont(labelFont);
        classLabel.setFont(labelFont);
        ageLabel.setFont(labelFont);
        idLabel.setFont(labelFont);

        JButton saveButton = new JButton("Save");
        JButton cancelButton = new JButton("Cancel");

        JTextField nameField = new JTextField();
        JTextField ageField = new JTextField(3);
        JTextField idField = new JTextField();

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
        

        add(classLabel);
        add(dropDown);
        add(cancelButton);

        add(ageLabel);
        add(ageField);
        add(Box.createRigidArea(new Dimension(0,0)));
        
        add(idLabel);
        add(idField);
        add(Box.createRigidArea(new Dimension(0,0)));

        saveButton.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    FileIO addStudent = new FileIO();
                    String className = (String)dropDown.getSelectedItem();
                    String firstName = nameField.getText();
                    String lastName = nameField.getText();
                    int age =  Integer.parseInt(ageField.getText());
                    String id = idField.getText();
                    System.out.println(0);
                    student newStudent = new student();
                    newStudent.setStudentInfo(firstName, lastName, age, id);
                    System.out.println(1);
                    addStudent.appendStudent(newStudent, className);
                    System.out.println(2);
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
        List<String> classList = new ArrayList<String>();
        classList = io.readClassList("Mario");
        String[] classArray = new String[classList.size()];
        for(int i=0; i < classList.size(); i++){
            classArray[i] = classList.get(i);
        }
        JComboBox box = new JComboBox(classArray);
        return box;
    }
}