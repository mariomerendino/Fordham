/* * * * * * * * * * * * * * * * * * * * *
 * GRADEBOOK                             *
 * FILE I/O CLASS                        *
* * * * * * * * * * * * * * * * * * * * */
package Logic;
import java.util.*;
import java.io.*;
import javax.swing.*;

public class FileIO{
	public static teacher currentTeacher;

	String username = teacher.getuserName();

	String userPath = (System.getProperty("user.dir") + "/data/" + username + '/');

//	public FiloIO(teacher t1){
//		currentTeacher = t1;
//	}

	//Creates Main DATA folder if it doesnt already exist. 
	public void createMainDirectory(){
	        try{
            String currentDir = System.getProperty("user.dir");
            File dir = new File (currentDir + "/data");
            if (dir.exists()){

            }
            else{
                dir.mkdir();
				
            }
        }
        catch(Exception e){

        }   
	}
	public void teacherRegistration(){
		try{
			//Attempts to create the main directory.
			createMainDirectory();
			//Opens the data Folder.
			String currentDir = System.getProperty("user.dir");
            File dir = new File (currentDir + "/data");
			//Creates a New Teacher Object.
			teacher t1 = new teacher();

			//inputs all info
			t1.setuserName(JOptionPane.showInputDialog("Please Create a UserName: "));
			t1.setpassword(JOptionPane.showInputDialog("Enter a password: "));
			t1.setfirstName(JOptionPane.showInputDialog("Enter your First Name: "));
			t1.setlastName(JOptionPane.showInputDialog("Enter your Last Name: "));
			File userDirectory = new File (currentDir + "/data/" + t1.getuserName());
			userDirectory.mkdir();
			File passwordFile = new File (userDirectory + "/" + t1.getuserName() + ".txt");
			FileWriter fw = new FileWriter(passwordFile.getAbsoluteFile(), true);
			BufferedWriter bw = new BufferedWriter(fw);
			bw.write(t1.getuserName() + "\n");
			bw.write(t1.getpassword() + "\n");
			bw.write(t1.getfirstName() + "\n");
			bw.write(t1.getlastName() + "\n");
			bw.close();
		}
		catch (Exception e){

		}
	}
	//CREATE DIRECTORY, CALLED FROM ADD CLASS
	public void createDirectory(String path) {
		try {
			//create string for path
			File outputFile = new File(System.getProperty("user.dir") + '/' + path + ".csv");
			//check for dubplicate classes by checking
			//directories
			if (outputFile.getParentFile( ).exists( )) {
				System.out.println("This class already exists.");
			}
			else
			//create the directory if it doesn't exist
			if (!outputFile.getParentFile( ).exists( )) {
				outputFile.getParentFile( ).mkdirs( );
				System.out.println("New directory created.");
			}
			//create the file in the directory if it doesn't exist
			if (!outputFile.exists( )) {
				//instantiate streams/buffers
				FileWriter fw = new FileWriter(outputFile.getAbsoluteFile( ), true);
				BufferedWriter bw = new BufferedWriter(fw);
				//create class file for student info
				outputFile.createNewFile( );
				System.out.println("New file created in directory.");
			}
		 }catch (IOException e) {
				System.out.println("Error");
		}

	}

	public void addToClassList(String username, String className) {
		List<String> tempList = new ArrayList<String>( );
		boolean newClass = true;		

		System.out.println("ADD TO CLASS LIST current teacher: " + currentTeacher.username);

		try {
			File outputFile = new File(userPath + "/class_list.csv");
	
//			File outputFile = new File(System.getProperty("user.dir") + "/data/" + username + "/class_list.csv");
			FileWriter fw = new FileWriter(outputFile.getAbsoluteFile( ), true);
			BufferedWriter bw = new BufferedWriter(fw);
			System.out.println("try addToClastList");
			

			if (!outputFile.exists( )) {
				System.out.println("CLASS FILE");
				outputFile.createNewFile( );
			}

			//read file to stop duplicates
			tempList = readClassList(username);			
			//search for string in file
			String search = className;
			for(String str: tempList) {			
				if(str.trim( ).contains(search))
					newClass = false;		

			}	

			//append class name if it's new
			if (newClass == true) {
				System.out.println("new class");
				bw.write(className);
				bw.write('\n');
				bw.close( );
			
			}
			else
				System.out.println("Class already in list.");
		} catch (IOException ex) {
			System.out.println(ex);
		}
	}	

	//read class names in from file
	public List<String> readClassList(String username) {
		String fileName = (System.getProperty("user.dir") + "/data/" +username + "/class_list.csv");
		String thisLine = null;
		boolean empty = false;
		List<String> classList = new ArrayList<String>( );
		int counter = 0;

		System.out.println("Reading class file...");

		try {
			InputStream ips = new FileInputStream(fileName);
			InputStreamReader ipsr = new InputStreamReader(ips);
			BufferedReader br = new BufferedReader(ipsr);
			String line;
			while ((line = br.readLine( )) != null) {
				classList.add(line);				
				System.out.println(line + " class read");

			}
			br.close( );
		} catch (IOException e) {
			System.out.println(e);
		}
		return classList;
	}

/*			
	public void editClassInfo(String className, char t) {
		String fileName = (System.getProperty("user.dir") + '/' + className);
	
		try {
			File outputFile = new File(fileName);
			FileWriter fw = new FileWriter(outputFile.getAbsoluteFile( ), true);
			BufferedWriter bw = new BufferedWriter(fw);
			if (!outputFile.getParentFile( ).exists( ))
				System.out.println("This class does not exist.");
			else {
				student s = new student( );
				s.inputStudent( );				
				appendStudent(s, className);			


			}
		} catch (IOException ex) {
			System.out.println(ex);
		}
	}			
*/

	//APPEND STUDENT, CALLED FROM ADD STUDENT
        public static void appendStudent(student s, String className) {
	    String fileName = (System.getProperty("user.dir") + "/data/" + currentTeacher.username +'/' + className + '/' + className +  ".csv");
		
		try {
			File outputFile = new File(fileName);
			FileWriter fw = new FileWriter(outputFile.getAbsoluteFile( ), true);
			BufferedWriter bw = new BufferedWriter(fw);

			//alert user if file doesn't exist
			if (!outputFile.exists( ))
				System.out.println("This class does not exist.");
			//if the file exists	
			else {
				bw.newLine();
				bw.write(s.lastName + ',' + s.firstName + ',' + s.age + ',' + s.idNumber + "\n");
				bw.close( );
				addToMasterStudentList(s);
			}
		} catch(IOException ex) {
			System.out.println("Error opening file.");
		}

	}


	public static void addToMasterStudentList(student s) {
		String fileName = (System.getProperty("user.dir") + "/data/" + currentTeacher.username + "/master_student_list.csv");
//		List<String> studentList = new ArrayList<String>( );
		boolean newStudent = true;

		try {
			File outputFile = new File(fileName);
			FileWriter fw = new FileWriter(outputFile.getAbsoluteFile( ), true);
			BufferedWriter bw = new BufferedWriter(fw);

			if(!outputFile.exists( ))
				outputFile.createNewFile( );

			List<String> tempList = new ArrayList<String>( );

			tempList = readMasterStudentList(currentTeacher.username);

			String search = s.idNumber;

			System.out.println("s.idNumber: " + s.idNumber);

			for (String str:tempList) {
				if(str.trim( ).contains(search))
					newStudent = false;
			}

			if (newStudent == true) {
				bw.newLine();
				bw.write(s.idNumber + ',' + s.lastName + ',' + s.firstName + ',' + s.age + "\n");
				bw.close( );
			}
			else
				System.out.println("Not a new student");

		}
		catch (IOException ex) {
			System.out.println(ex);
		}
	}

	public static List<String> readMasterStudentList(String username) {
		String fileName = (System.getProperty("user.dir") + "/data/" + username + "/master_student_list.csv");
		List<String> studentIDList = new ArrayList<String>( );
		String studentID;

		List<String> studentLine = new ArrayList<String>( );

		try {
			InputStream ips = new FileInputStream(fileName);
			InputStreamReader ipsr = new InputStreamReader(ips);
			BufferedReader br = new BufferedReader(ipsr);
//			Scanner s = new Scanner(fileName);
			String line;
			int counter = 0;
			
			while((line = br.readLine( )) != null) {
				String[ ] s = line.split(",");
				System.out.println(s[counter]);
				studentIDList.add(s[counter]);
				studentLine.add(line);
//				System.out.println(studentLine);
//				studentIDList[counter] = br.nextInt( );
//				br.nextLine( );
//				studentList[counter] = studentID;
//				counter++;
			}


			br.close( );
		} catch(IOException e) {
			System.out.println(e);
		}

		System.out.println("User ID List");
		for (int i = 0; i < studentIDList.size( ); i++)
			System.out.println(studentIDList.get(i) + "\n");

		return studentIDList;
	}
			

	public void appendGrade(student s, classroom c, gradedAssignment g, String className) {
		
		String fileName = (System.getProperty("user.dir") + '/' + className + "/grades.csv");		
		
		System.out.println("\n" + System.getProperty("user.dir"));
		System.out.println(fileName);		

		try {
			File outputFile = new File(fileName);
			FileWriter fw = new FileWriter(outputFile.getAbsoluteFile( ), true);
			BufferedWriter bw = new BufferedWriter(fw);

			if (!outputFile.exists( ))
				System.out.println("Grades file does not exist.");
			else {
				bw.write(s.lastName + ',' + s.firstName + ',' + g.name + ',' + g.score + "\n");
				bw.close( );
			}
		} catch(IOException ex) {
			System.out.println("Error opening grade file.");
		}

	}

	public void readStudent(String className) {
		//create full path to file
		String fileName = (System.getProperty("user.dir") + '/' + className + '/' + className + ".csv");
		String thisLine = null;
		//used to return true/false to appendStudent( ) to tell if
		//the file is empty	
		boolean empty = false;

		System.out.println("Reading student information from file...");


		try {
			//create input stream, input stream reader, and buffered reader
			InputStream ips = new FileInputStream(fileName);
			InputStreamReader ipsr = new InputStreamReader(ips);
			BufferedReader br = new BufferedReader(ipsr);
			String line;

			//read from file while the next line is filled
			while ((line = br.readLine( )) != null)
				System.out.println(line);

			//close buffered reader stream
			br.close( );
		} catch (IOException e) {
			System.out.println("Error");

		}
	
	}
	public boolean login(String username, String password){
	    try{
            String currentDir = System.getProperty("user.dir");
            File dir = new File (currentDir + "/data/" + username);
            File passwordFile = new File (dir + "/" + username + ".txt");
            FileReader passFileReader = new FileReader(passwordFile);
            BufferedReader reader = new BufferedReader (passFileReader);
			String pass = new String();
			for (int i=0; i < 2; i++){
            	pass = reader.readLine();
			}
            reader.close();
            if (dir.exists() && password.equals(pass)){
				return true;
            }
            else{
				return false;
            }
        }
        catch (Exception e){
            JOptionPane.showMessageDialog(null, "ERROR: Exception");
        }
		return false;
    }

	public teacher readTeacher(String usr){
		teacher t1 = new teacher();
		try{
			String currentDir = System.getProperty("user.dir");
			File dir = new File (currentDir + "/data/" + usr);
			File userFile = new File (dir + "/" + usr + ".txt");
			FileReader userFileReader = new FileReader(userFile);
			BufferedReader reader = new BufferedReader (userFileReader);
			
			t1.setuserName(reader.readLine());
			t1.setpassword(reader.readLine());
			t1.setfirstName(reader.readLine());
			t1.setpassword(reader.readLine());

			reader.close();
		}
		catch (Exception e){

		}
		return t1;
	}

}

