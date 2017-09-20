package GUI;
import Logic.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;

public class login extends JFrame{
    
    //Declares all text fields and buttons
    javax.swing.JButton loginButton = new JButton();
    javax.swing.JButton registerButton = new JButton();
    javax.swing.JPasswordField passwordField = new JPasswordField(8);
    javax.swing.JLabel passwordLabel = new JLabel();
    javax.swing.JLabel usernameLabel = new JLabel();
    javax.swing.JTextField usernameField = new JTextField(8);

    public login(){
        //Creates a Listener for the login button
        loginButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                loginButtonActionPerformed(evt);
            }
        });
        //creates a Listener for the registerButton
        registerButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                registerButtonActionPerformed(evt);
            }
        });
        //sets size
        setSize(250,200);
        //Sets layout to be a flow layout.
        FlowLayout fLayout = new FlowLayout(FlowLayout.LEFT,10,20);
        setLayout(fLayout);
        //Sets values for all objects in the GUI
        usernameLabel.setText("Username: ");
        passwordLabel.setText("Password: ");
        usernameField.setText("");
        passwordField.setText("");
        loginButton.setText("Enter");
        registerButton.setText("Register");
        //Adds all objects to the Frame
        add(usernameLabel);
        add(usernameField);
        add(passwordLabel);
        add(passwordField);
        add(loginButton);
        add(registerButton);
        //Sets its visibility
        setVisible(true);
        
    }
    /*public static void main ( String [] args ){
        login t = new login();
    }*/
    private void registerButtonActionPerformed(java.awt.event.ActionEvent evt) {
        FileIO io = new FileIO();
        io.teacherRegistration();
        
    }
    private void loginButtonActionPerformed(java.awt.event.ActionEvent evt) {
        FileIO io = new FileIO();
        String pass = new String(passwordField.getPassword());
        if(io.login(usernameField.getText(), pass)){
            teacher t1 = new teacher();
            t1 = io.readTeacher(usernameField.getText());
            gradebook g = new gradebook(t1);
            dashboard frame = new dashboard();
            dispose();
        }
        else{
            JOptionPane.showMessageDialog(null,"ERROR: Incorrect username or password ");
        }
    }
}