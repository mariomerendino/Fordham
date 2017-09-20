//Author: Mario J. Merendino
//Professor David Wei
//Java Programming
//February 20, 2017
//WebAddress: http://storm.cis.fordham.edu/~merendino/Java/InsertionSort/insertionSort.html
//This program sorts an arrays in ascending & Descending order


import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;
import javax.swing.*;
public class SortingProg extends Applet implements ActionListener{

    //original array
    int a[] = { 55, 25, 66, 45, 8, 10, 12, 89, 68, 37 };
    int b[] = { 55, 25, 66, 45, 8, 10, 12, 89, 68, 37 };

    //buttons for ascending or Descending
    Button original;
    Button sortA;
    Button sortD; 
    
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
        x+=15;
        y+=15;
        for(int i=0; i<b.length; i++){
            g.drawString(String.valueOf(b[i]),x,y);
            x+=20;
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
    }
}