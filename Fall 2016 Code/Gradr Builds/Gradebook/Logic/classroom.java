package Logic;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.io.*;

public class classroom{
    int numStudents;
    int MAX_STUDENTS = 20;
    public teacher currentTeacher;
    String className;
    public static List<student> studentList = new ArrayList<student>();
    public classroom(){
        
    }
    public classroom(teacher t){
        currentTeacher = t;
    }
    public classroom(String n){
        className = n;
    }
	public void edit(){
		classroom x = new classroom(className);
		int choice = 1;
		while (choice != 0){
			Scanner userInput = new Scanner (System.in);
			System.out.print(className + "\n");
			System.out.print("What would you like to do?\n");
			System.out.print ("\t1)Add Students\n\t2)Add a grade for a student\n\t3)Display Students\n\t0)Quit\n");
			choice = userInput.nextInt();
			switch(choice){
				case 1:
					inputStudents();
					break;
				case 2:
					FileIO gradeFile = new FileIO( );
					gradedAssignment g = new gradedAssignment( );
					g.inputInfo( );
					student s = new student( );
					gradeFile.appendGrade(s, x, g, className);
					break;
                		case 3:
                    			displayStudents();
                    			break;
                		case 0:
                    			break;
            		}
        	}
    }

    public void inputStudents(){
	    FileIO printStudent = new FileIO();
        boolean cnt = true;
        while( cnt == true){
            Scanner userInput = new Scanner (System.in);
            System.out.println("Would like to add another student?(Y/N)");
            String ans;
            ans = userInput.next();
            if (ans.equals("Y") || ans.equals("y")){
                student s = new student();
                s.inputStudent();
                studentList.add(s);
                printStudent.appendStudent(s, className);
	    }		
	   
            else{
                cnt = false;
            }
        }
    }

    public void displayStudents(){
        System.out.println("displayStudents( )");
        FileIO read = new FileIO( );
        read.readStudent(className);
    }
    public static void displayStudentsList(){
        for(int i=0; i < studentList.size(); i++){
             System.out.println("Student " + i + ")" + studentList.get(i).getFirstName() + " " + studentList.get(i).getLastName());
        }
    }
    public String getName(){
        return className;
    }
    public void setName(String n){
        className = n;
    } 
}
