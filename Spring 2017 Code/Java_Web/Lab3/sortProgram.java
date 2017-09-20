import java.io.*;
import java.util.*;
import java.awt.*;
import java.applet.Applet;
import javax.swing.*;
import java.awt.event.*;


public class sortProgram extends Applet implements ActionListener,KeyListener{
    //UI Components
    Label prompt;
    TextField userInput;
    Button add;
    Button originalSort;
    Button ascending;
    Button descending;
    Button clear;
    Button max;
    Button min;
    Label sumLabel; 
    Label averageLabel;

    //Data
    int[] array = new int[10];
    int[] originalArray= new int[10];
    int logicalSize = 0;
    int currentSize = 10;
    int sum = 0;
    int average;

    //Button Logic for printing out to the main screen. 
    Boolean original = true;
    Boolean isASort = false;
    Boolean isDSort = false;
    Boolean isMax = false;
    Boolean isMin = false;
    //paints the correct String and the array
    public void paint(Graphics g){
        //Prints if user wants original data
        if (original){
            print(g,"Data items in original order\n",originalArray,300,70);
            original = false;
        }

        //Prints if user wants Ascending data
        if(isASort){
             print(g,"Data items in Ascending order\n",array,300,70);
             isASort = false;
        }

        //Prints if user wants descending data
        if(isDSort){
             print(g,"Data items in Descending order\n",array,300,70);
             isDSort = false;
        }

        //Prints if user wants Max Value
        if(isMax){
            sortDesc();
            print2(g,"Maximum Value\n", array[0] ,300,70);
            isMax = false;
        }

        //Prints if user wants Min Value
        if(isMin){
            sortDesc();
            print2(g,"Minimum Value\n", array[logicalSize-1] ,300,70);
            isMin = false;
        }
    }
    //Prints Text & Arrays
    public void print(Graphics g, String head, int b[], int x, int y){

        g.drawString(head,x,y);
        y+=15;
        for(int i=0; i<logicalSize; i++){
            g.drawString(String.valueOf(b[i]),x,y);
            x = x + 10 + (String.valueOf(b[i]).length()*10);
            if (i % 15 == 0 && i != 0){
                y+=20;
                x=300;
            }
        }

    }
    //Prints A String, and A Number
    public void print2(Graphics g, String head, int z, int x, int y){

        g.drawString(head,x,y);
        y+=15;
        g.drawString(String.valueOf(z),x,y);
        x+=20;

    }

    //Init: Called upon start.
    //Placement & Settings of all UI Components
    public void init(){
        //Creates a Main JPanel with a BorderLayout
        JPanel main = new JPanel();
        main.setLayout(new BorderLayout());

        //Creates a Bar at the top of the borderLayout
        JPanel northBar = new JPanel();
        //Has its own Flow Layout
        northBar.setLayout(new FlowLayout(1));
        northBar.setBackground(Color.WHITE);

        //Sets the Prompt Label to prompt user
        prompt = new Label("Please enter an Integer");
        //Adds it to the North Bar
        northBar.add(prompt);
        
        //Sets the Userinput TextField to have 3 char spaces
        userInput = new TextField(3);
        northBar.add(userInput);
        //Adds a key listener so if the enter button is hit. 
        userInput.addKeyListener(this);
        
        add = new Button("Add to Array");
        northBar.add(add);
        add.addActionListener(this);

        clear = new Button("Clear");
        northBar.add(clear);
        clear.addActionListener(this);

        sumLabel = new Label("Sum = 0      ");
        northBar.add(sumLabel);
    
        averageLabel = new Label("Average = 0      ");
        northBar.add(averageLabel);

        //Adds the North Bar to the entire main JPanel. 
        main.add(northBar, BorderLayout.NORTH);

        //Creates a Jpanel that is a vertical bar of components. 
        JPanel westBar = new JPanel();
        westBar.setLayout(new BoxLayout(westBar, BoxLayout.Y_AXIS));
        westBar.setBackground(Color.WHITE);

        originalSort = new Button("Original Order");
        westBar.add(originalSort);
        originalSort.addActionListener(this);
        
        ascending = new Button("Ascending");
        westBar.add(ascending);
        ascending.addActionListener(this);
        
        descending = new Button("Descending");
        westBar.add(descending);
        descending.addActionListener(this);
        
        min = new Button("Min Value");
        westBar.add(min);
        min.addActionListener(this);

        max = new Button("Max Value");
        westBar.add(max);
        max.addActionListener(this);
        
        main.add(westBar, BorderLayout.WEST);

        add(main);
        
    }
    //Adds to the orginal & sorted array.
    //Also calculates the sum of the array, and changes the label. 
    public void addToArray(){
        int newNum = Integer.valueOf(userInput.getText());
        //if the user inputs a value too large or small
        if (newNum > 999 || newNum < -999){
            //Creates a Popup that says its out of bounds. 
            JOptionPane.showMessageDialog(null,"Error: You cannot enter a Value greater than 999\n or less than -999","Mario J. Merendino", JOptionPane.ERROR_MESSAGE);
            //Exits function. 
            return;
        }
        if(logicalSize < array.length){ 
            originalArray[logicalSize] = newNum;
            array[logicalSize] = newNum;
            logicalSize++;
        }
        else{
            int[] temp = new int[array.length*2];
            int[] temp2 = new int[array.length*2];
            copyArrayData(originalArray, temp);
            copyArrayData(array, temp2);
            originalArray = temp;
            array = temp2;
            originalArray[logicalSize] = newNum;
            array[logicalSize] = newNum;
            logicalSize++;
        
        }
        sum = 0;
        for(int i =0; i < logicalSize; i++){
            sum = sum + originalArray[i];
        }
        
        average = sum/logicalSize;
        sumLabel.setText("Sum = " + Integer.toString(sum));
        averageLabel.setText("Average = " + Integer.toString(average));
    }
    public void copyArrayData(int a[], int b[]){
        for(int i = 0; i < a.length; i++){
            b[i] = a[i];
        }
    }
    //sorts array in ascending order
    public void sortAsc(){
        int i, key;
        // Start with 1 (The second number in the array).
        for(int j=1; j < logicalSize; j++){    
            //set that equal to the key
            key = array[j]; 
            // larger values move up in the array
            for(i = (j - 1); (i >= 0) && (array[i] > key); i--){ 
                array[i+1] = array[i];
            }
            //Put key into its proper location
            array[i+1] = key;    
        }
        return;
    }
    //sorts array in descending order
    public void sortDesc(){
        int i, key;
        // Start with 1 (The second number in the array).
        for(int j=1; j < logicalSize; j++){    
            //set that equal to the key
            key = array[j]; 
            // larger values down in the array
            for(i = (j - 1); (i >= 0) && (array[i] < key); i--){ 
                array[i+1] = array[i];
            }
            //Put key into its proper location
            array[i+1] = key;    
        }
        return;
    }
    public void actionPerformed(ActionEvent e){
        //If the Ascending buttion is clicked
        if(e.getSource()==ascending){
            sortAsc();
            isASort = true;
            repaint();
        }
        //If the Descending buttion is clicked
        else if(e.getSource()==descending){
            sortDesc();
            isDSort = true;
            repaint();
        }
        //If the original buttion is clicked
        else if(e.getSource()==originalSort){
            original = true;
            repaint();
        }
        //If the add button is clicked
        else if(e.getSource()== add){
            addToArray();
            original = true;
            repaint();
            userInput.setText("");
        }
        //if the clear button is clicked. 
        else if(e.getSource()== clear){
            originalArray = new int[10];
            array = new int[10];
            logicalSize = 0;
            sum = 0;
            sumLabel.setText("Sum = 0      ");
            averageLabel.setText("Average = 0      ");
            repaint();
        }
        else if(e.getSource()== min){
            isMin = true;
            repaint();
        
        }
        else if(e.getSource()== max){
            isMax = true;
            repaint();
        }
    }
    //KeyListener Functions. 
    public void keyPressed(KeyEvent e){
        if (e.getKeyCode()==KeyEvent.VK_ENTER){
            addToArray();
            original = true;
            repaint();
            userInput.setText("");
        }
    }
    public void keyReleased(KeyEvent arg) {
    }
    public void keyTyped(KeyEvent arg0) {
    }
}