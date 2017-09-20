import java.util.*;
public class collegeStudent extends student{
    public String collegeName;
    public String dorm;

    public void inputCollgeInfo(){
        Scanner userInput = new Scanner (System.in);
        System.out.println("Input collegeName");
        collegeName = userInput.nextLine();
        System.out.println("Input dorm");
        dorm = userInput.nextLine();
    }
    public void displayCollegeInfo(){
        System.out.println(collegeName);
        System.out.println(dorm);
    }
    public void equal(collegeStudent x){
        firstName = x.firstName;
        lastName = x.lastName;
    }

}