//Author: Mario J. Merendino
//Professor David Wei
//Java Programming
//March 6, 2017
//WebAddress: http://storm.cis.fordham.edu/~merendino/Java/Lab2/insertionSort.html
//This program sorts an arrays in ascending & Descending order

import java.util.*;
import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;
import javax.swing.*;
public class SortingProg extends Applet implements ActionListener{
    //original array
    public int a[];
    public int b[];

    //All the GUI elements (buttons & TextFields)
    TextField size;
    Label sizeLabel;
    Button original;
    Button sortA;
    Button sortD;
    Button random;
    
    //booleans for determining what to print
    Boolean start = true;
    Boolean isASort = false;
    Boolean isDSort = false;
    //paints the correct String and the array
    public void paint(Graphics g){
        if (start){
            print(g,"Data items in original order\n",b,25,50);
            start = false;
        }
        if(isASort){
             print(g,"Data items in Ascending order\n",a,25,50);
             isASort = false;
        }
        if(isDSort){
             print(g,"Data items in Descending order\n",a,25,50);
             isDSort = false;
        }
    }
    //Sets the values for the buttons, adds them to the page. 
    public void init(){
        sizeLabel = new Label("Size");
        add(sizeLabel);
        size = new TextField(5);
        size.setText("10");
        add(size);

        random = new Button("Random Fill");
        add(random);
        //adds an actionlistener for reset button
        random.addActionListener(this);

        
        original = new Button("Orignal");
        add(original);
        //adds an actionlistener for orignal button
        original.addActionListener(this);

        sortA = new Button("Ascending");
        add(sortA);
        //adds an actionlistener for ascending button
        sortA.addActionListener(this);

        sortD = new Button("Descending");
        add(sortD);
        //adds an actionlistener for Descending button
        sortD.addActionListener(this);
        
        //Fills the Array with random data in the beginning.
        fillRandom();
    }
    public void sortAscending(){
        int i, key;
        // Start with 1 (The second number in the array).
        for(int j=1; j < a.length; j++){    
            //set that equal to the key
            key = a[j]; 
            // larger values move up in the array
            for(i = (j - 1); (i >= 0) && (a[i] > key); i--){ 
                a[i+1] = a[i];
            }
            //Put key into its proper location
            a[i+1] = key;    
        }
        return;
    }
    public void sortDescending(){
        int i, key;
        // Start with 1 (The second number in the array).
        for(int j=1; j < a.length; j++){    
            //set that equal to the key
            key = a[j]; 
            // larger values down in the array
            for(i = (j - 1); (i >= 0) && (a[i] < key); i--){ 
                a[i+1] = a[i];
            }
            //Put key into its proper location
            a[i+1] = key;    
        }
        return;
    }
    //prints the string first, then the array
    public void print(Graphics g, String head, int b[], int x, int y){

        g.drawString(head,x,y);
        y+=15;
        for(int i=0; i<b.length; i++){
            g.drawString(String.valueOf(b[i]),x,y);
            x+=20;
            if (i % 30 == 0 && i != 0){
                y+=20;
                x=25;
            }
        }

    }
    //Fills the array with random values
    public void fillRandom(){
        
        int random;
        int userSize;
        
        try{
            //gets Size of array from user input from the TextBox.
            userSize = Integer.valueOf(size.getText());

             // If their input is greater than 100 display a warning.
            if (userSize > 100){
                JOptionPane.showMessageDialog(null, "ERROR: Too many Objects!\n Range: 1 - 100");

            }
            //if their input is less than 1 display a warning
            else if(userSize < 1){
                JOptionPane.showMessageDialog(null, "ERROR: Enter more than one Object!\n Range: 1 - 30");
            }
            //Or else fill the array with the amount of data inputed by the user. 
            else{
                //dynamically allocate memory for the array
                a = new int[userSize];
                b = new int[userSize];
                for (int i=0; i < userSize; i++){
                    //creates a random integer 1-99
                    random = (int )(Math.random() * 99 + 1);
                    a[i] = random;
                    b[i] = random;
                }
            }
        }
        catch(Exception e){
            JOptionPane.showMessageDialog(null, "ERROR: Input an Integer!");
        }
    }
    //Action Listners
    public void actionPerformed(ActionEvent e){
        //If the Ascending buttion is clicked
        if(e.getSource()==sortA){
            sortAscending();
            isASort = true;
            repaint();
        }
        //If the Descending buttion is clicked
        else if(e.getSource()==sortD){
            sortDescending();
            isDSort = true;
            repaint();
        }
        //If the original buttion is clicked
        else if(e.getSource()==original){
            start = true;
            repaint();
        }
        else if(e.getSource()== random){
            fillRandom();
            start = true;
            repaint();
        }
    }
}