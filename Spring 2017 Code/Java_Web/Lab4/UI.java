import java.io.*;
import java.util.*;
import java.awt.*;
import java.applet.Applet;
import javax.swing.*;
import java.awt.event.*;
public class UI extends Applet implements ActionListener,KeyListener{

    ///Main function used for Offline use. You must change the class declaration  
    ///to inherit the JFrame Class, and not the Applet Class
    /*public static void main(String[] args){
        UI x = new UI();
        x.init();
    }*/
    //Creates an Object of SummableSet
    public SummableSet set = new SummableSet();

    //UI components
    Label prompt;
    TextField userInput;
    Button search;
    Button delete;
    Button addButton;
    Button clear;
    Button sum;
    //output label is used for all output, including errors. 
    Label outputLabel;

    //initializes all GUI components. 
    public void init(){

        //Sets Layout of entire Applet
        BorderLayout layout = new BorderLayout(3,3);
        setLayout(layout);

        
        //Creates two bars, one for the north & West
        JPanel northBar = new JPanel();
        JPanel westBar = new JPanel();
        //North bar is a flow layout
        northBar.setLayout(new FlowLayout());
        //Westbar has a vertical layout of buttons -
        westBar.setLayout(new BoxLayout(westBar, BoxLayout.Y_AXIS));
        northBar.setBackground(Color.WHITE);
        westBar.setBackground(Color.WHITE);

        //Sets and Adds text for prompting user [North]
        prompt = new Label("Please Enter a number");
        northBar.add(prompt);

        //Sets the Size of the Userinput textfield, and adds a Key listener [North]
        userInput = new TextField(3);
        northBar.add(userInput);
        userInput.addKeyListener(this);

        //Sets text & adds the add button [North]
        addButton = new Button("Add To Data Set");
        northBar.add(addButton);
        addButton.addActionListener(this);

        //Sets text & adds the delete button [North]
        delete = new Button("Remove From Data Set");
        northBar.add(delete);
        delete.addActionListener(this);
        
        //Sets text & adds the search button [North]
        search = new Button("Search Data Set");
        northBar.add(search);
        search.addActionListener(this);

        add(northBar, BorderLayout.NORTH);
        //Sets text & adds the delete button [West]
        sum = new Button("Sum of Entire Data Set");
        westBar.add(sum);
        sum.addActionListener(this);

        //Sets text & adds the delete button [West]
        clear = new Button("Clear Data Set");
        westBar.add(clear);
        clear.addActionListener(this);

        add(westBar, BorderLayout.WEST);
        
        //Sets default text for the output label. adds it to the center panel 
        outputLabel = new Label("Sum = 0");
        add(outputLabel, BorderLayout.CENTER);
        
        //Necessary if running offline and class extends JFrame.
        setSize(800, 300);
        setVisible(true);
    }
    
    //Action Listeners for the buttons. 
    public void actionPerformed(ActionEvent e){
        if(e.getSource() == addButton){
            try{
                set.add(Integer.valueOf(userInput.getText()));
                outputLabel.setText(userInput.getText() + " added");
            }
            catch(Exception x){
                outputLabel.setText("ERROR: must be an Integer");
                userInput.setText("");
            }
        }

        if(e.getSource() == delete){
            try{
                set.remove(Integer.valueOf(userInput.getText()));
            }
            catch(IllegalArgumentException x){
                outputLabel.setText("ERROR: " + userInput.getText() + " Does not exist");
            }
            catch(Exception x){
                outputLabel.setText("ERROR: must be an Integer");
                userInput.setText("");
            }

        }

        if(e.getSource() == search){
            try{
                if(set.includes(Integer.valueOf(userInput.getText()))){
                    outputLabel.setText(userInput.getText() + " found");
                }
                else{
                    outputLabel.setText(userInput.getText() + " not found");
                }
            }
            catch(Exception x){
                outputLabel.setText("ERROR: must be an Integer");
                userInput.setText("");
            }
        }

        if(e.getSource() == clear){
            set = new SummableSet();
            outputLabel.setText("Data Set Cleared");
            userInput.setText("");
        }

        if(e.getSource() == sum){
            outputLabel.setText("Sum = " + Integer.toString(set.totalSum()));
        }
    }

    public void keyPressed(KeyEvent e){
        if (e.getKeyCode()==KeyEvent.VK_ENTER){
            try{
                set.add(Integer.valueOf(userInput.getText()));
                outputLabel.setText(userInput.getText() + " added");
                userInput.setText("");
            }
            catch(Exception x){
                outputLabel.setText("ERROR: must be an Integer");
            }
        }
    }
    public void keyReleased(KeyEvent arg) {
    }
    public void keyTyped(KeyEvent arg0) {
    }
}