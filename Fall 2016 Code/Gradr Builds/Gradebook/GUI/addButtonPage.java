package GUI;
import Logic.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.util.List;
import java.awt.event.*;

public class addButtonPage extends JFrame{
    public addButtonPage(){
        try{
            
            String prompt = new String("Would you like to add a...");
            JLabel promptLabel = new JLabel();
            Font promptFont= new Font("Stencil", Font.PLAIN, 32);
            setResizable(false);
            setVisible(true);
            setSize(400,300);
            GridLayout layout = new GridLayout(3,0);
            JButton studentButton = new JButton("Student");
            JButton classButton = new JButton("Class");
            
            studentButton.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    addStudentPage studentPage = new addStudentPage();
                    dispose();
                }
            });
            classButton.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    addClassPage classPage = new addClassPage();
                    dispose();
                }
            });
            setLayout(layout);
            promptLabel.setText(prompt);
            promptLabel.setFont(promptFont);
            add(promptLabel);
            add(studentButton);
            add(classButton);
        }
        catch (Exception e){
            
        }
    }
}