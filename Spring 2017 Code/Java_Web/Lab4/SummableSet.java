import java.util.*;

public class SummableSet extends IntSet {
    private int sum = 0;
    public int totalSum(){
        return sum;
    
    }
    public void add(int x){
        super.add(x);
        sum = sum + x;
    }
    public void remove(int x){
        if(super.includes(x)){
            sum = sum-x;
        }
        super.remove(x);

    }
    //Main Function Used for Testing & Debugging in a terminal. 
    /*public static void main(String[] args){
        SummableSet x = new SummableSet();
        Boolean loop = true;
        Scanner input = new Scanner(System.in);
        while(loop){
            System.out.println("Sum = " + Integer.toString(x.totalSum()));
            System.out.println("1. Add\n2.Remove\n3. Display\n4. exit");
            int choice = input.nextInt();
            switch (choice) {
                case 1: 
                    System.out.println("what number do you want to Add");
                    x.add(input.nextInt());
                    break;
                case 2:
                    System.out.println("Which number do you want to remove");
                    x.remove(input.nextInt());
                    break;
                case 3:
                    System.out.println(x.listAsString() + "\n");
                    break;
                case 4:
                    loop = false;
                    break;
                default:
                    System.out.println("ERROR");
                    break;
            }

        }
    }*/

}