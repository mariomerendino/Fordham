import java.util.*;
import java.lang.Object;
import javax.swing.JOptionPane;
public class test{
    public test(){

    }
    public static void main( String[] args){
        int [] array;
        Scanner userInput = new Scanner (System.in);
        array = new int[10];
        System.out.print("Input 10 numbers");
        for (int i = 0; i < 10; i++){
            array[i] = userInput.nextInt();
        }
        displayArray(array, 10);
    }
    public static void displayArray(int a[], int size){
        String test = "";
        for (int i = 0; i < 10; i++){
            test = test + " " + a[i];
        }
        JOptionPane.showMessageDialog(null, test);
    }
}