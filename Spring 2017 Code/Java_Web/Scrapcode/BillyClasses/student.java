import java.util.*;
public class student{
    public String firstName;
    public String lastName;
    public int age;
    public int avg; 

    public student(){
        firstName = "Billy";
        lastName = "McBurnie";
        age = 21;
        avg = 90;
    }
    public void print(){
        System.out.println(firstName); 
        System.out.println(lastName);
        System.out.println(String.valueOf(age));
        System.out.println(String.valueOf(avg));
    }
    public void input(){
        Scanner userInput = new Scanner (System.in);
        System.out.println("Input First Name");
        firstName = userInput.nextLine();
        System.out.println("Input Last Name"); 
        lastName = userInput.nextLine();
        System.out.println("Input age"); 
        age = userInput.nextInt();
        System.out.println("Average"); 
        avg = userInput.nextInt();
    }
}