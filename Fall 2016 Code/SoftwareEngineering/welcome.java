import javax.swing.*;

public class welcome{
    public static void main ( String [] args ){
        JOptionPane.showMessageDialog(null, "HelloWorld", "Label", JOptionPane.PLAIN_MESSAGE); //position, words, label, icon
        String name = JOptionPane.showInputDialog(null, "Enter Name", "Yabish", JOptionPane.PLAIN_MESSAGE );

    }
}
