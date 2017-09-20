/* Author: Mario Merendino
 * Professor Papadakis
 * CS2000
 * Desc: Allows a user to set different datamembers of a student using classes
 * Last Modified: Sept 26, 2015
*/
#include <iostream>
#include <string.h>
using namespace std;

class Undergraduate {
    
public: //Methods
    
    Undergraduate (string f, string l, char  m, int mm, int dd, int yyyy){ //Constructor for Name and D.O.B
        fname = f;
        lname = l;
        mi = m;
        month = mm;
        day = dd;
        year = yyyy;
        
    }
    void setfname() { //Prompts user to enter  the first name
        cout << "Enter the students first name ";
        cin >> fname;
        change_fname(fname);
    }
    
    void setlname() {//Prompts user to enter the last name
        cout << "Enter the students last name " << endl;
        cin >> lname;
        change_lname(lname);
    }
    void setmi() {//Prompts user to enter the middle initial
        cout << "Enter the students middle initial " << endl;
        cin >> mi;
        change_mi(mi);
    }
    void change_fname(string f){ //Mutator for fname
        fname = f;
    }
    void change_lname(string l){ //Mutator for lname
        lname = l;
    }
    void change_mi(char m) { //Mutator for mi
        mi = m;
    }
    string get_fname() { //Accessor for fname
        return fname;
    }
    string get_lname() { //Accessor for Lname
        return lname;
    }
    char get_mi() { //Accessor for mi
        return mi;
    }
    void set_month(int mm){ //Mutator for month
        month = mm;
    }
    void set_day(int dd){ //Mutator for day
        day = dd;
    }
    void set_year(int yyyy){ //Mutator for year
        year = yyyy;
    }
    int get_month(){ //Accessor for month
        return month;
    }
    int get_day(){ //Accessor for day
        return day;
    }
    int get_year(){//Accessor for Year
        return year;
    }
    void setbirthday(){ //Sets the students birthday
        int m, d, y;
        cout << "Enter the Students birthday (mm/dd/yyyy)";
        cin >> m >> d >> y;
        set_month(m);
        set_day(d);
        set_year(y);
        
    }
    void setgender() { //Prompts user to enterthe Students gender
        char choice;
        cout << "Select gender " << endl;
        cout << "M. Male" << "\tF. Female\n";
        cin >> choice;
        switch(choice){
            case 1:
                change_gender('M');
                break;
            case 2:
                change_gender('F');
                break;
        }
    }
    void change_gender(char sex){ //mutator for gender
        gender = sex;
    }
    char get_gender(){ //Accessor for Gender
        return gender;
    }
    void setstudentid() { //Sets the Students ID number
        cout << "Enter Student ID: " << endl;
        cin >> studentid;
        change_studentid(studentid);
    }
    void change_studentid(string sid) { //Mutator for student ID
        studentid = sid;
    }
    string get_studentid() { //Accessor for Students Id
        return studentid;
    }
    void setstatus() { //Prompts user to enter students status as a student
        int choice;
        cout << "Is the Student: "<< endl;
        cout << "1. Active\n" << "2. Graduated\n" << "3. Withdrawn\n" << " 4. Sabatical" <<endl;
        cin >> choice;
        switch (choice){
            case 1:
                change_status("Active");
                break;
            case 2:
                change_status("Graduated");
                break;
            case 3:
                change_status("Withdrawn");
                break;
            case 4:
                change_status("Sabatical");
                break;
        }
    }
    void change_status(string s){ //Mutator for Status
        status = s;
    }
    string get_status(){ //Accessor for Status
        return status;
    }
    
    void setgterm() { //Prompts user to set Theyre expected grad term
        int choice;
        cout << "Enter Expected Graduation Term: " << endl;
        cout << "1. Fall\n" << "2. Spring\n";
        cin >> choice;
        switch (choice){
            case 1:
                change_gterm("Fall");
                break;
                
            case 2:
                change_gterm("Spring");
                break;
        }
    }
    void change_gterm(string g){//Mutator for grad term
        gterm = g;
    }
    string get_gterm() { //Accessor for grad term
        return gterm;
    }
    void setcampus(){ //Prompts user to enter the campus
        int choice;
        cout << "Enter the campus of the student: " << endl;
        cout << "1. RoseHill" << "\n2. LincolnCenter" << "\n3. Westchester\n";
        cin >> choice;
        switch (choice){
            case 1:
                change_campus("RH");
                break;
            case 2:
                change_campus("LC");
                break;
            case 3:
                change_campus("WC");
                break;
        }
    }
    void change_campus (string c){ //Mutator for campus
        campus = c;
    }
    string get_campus(){ //Accessor for campus
        return campus;
    }
    void setdegree() { //Prompts user to enter the type of degree they want
        int  choice;
        cout << "Enter Degree: " << endl;
        cout << "1. BS" << "\n2. BA\n";
        cin >> choice;
        switch(choice) {
            case 1:
                change_degree("BS");
                break;
            case 2:
                change_degree("BA");
                break;
        }
    }
    void change_degree (string d){ //Mutator for Degree
        degree = d;
    }
    string get_degree(){ //Accessor for degree
        return degree;
    }
    void setcredits() { //Prompts user to enter the number of credits earned
        cout << "Enter the total number of credits earned by the end of last semester: " << endl;
        cin >> credits;
        change_credits(credits);
    }
    void change_credits(int creds){ //Mutator for credits
        credits = creds;
    }
    int get_credits(){ //Accessor for credits
        return credits;
    }
    void setgpa() { //Prompts user to enter gpa
        cout << "Enter the students gpa: " << endl;
        cin >> gpa;
        change_gpa(gpa);
    }
    void change_gpa(double avg){ //Mutator for gpa
        gpa = avg;
    }
    double get_gpa(){//Accessor for gpa
        return gpa;
    }
    void setcellphone() {//Prompts user to enter cell number
        cout << " Enter Cellphone Number: " << endl;
        cin >> cellphone;
        change_cellphone(cellphone);
    }
    void change_cellphone(string cell){ //mutator for cell number
        cellphone = cell;
    }
    string get_cellphone(){ //accessor for cell number
        return  cellphone;
    }
    void sethomephonenumber(){//prompts user to enter cell number
        cout << "Enter phone number: ";
        cin >> homephonenumber;
        change_homephonenumber(homephonenumber);
    }
    void change_homephonenumber (string home){ //mutator for cell
        homephonenumber = home;
    }
    string get_homephonenumber(){//accessor for home fphone
        return homephonenumber;
    }
    void setpref() {//prompts user to enter prefered number
        char choice ;
        cout << "Enter preferred phone: " << endl;
        cout << "C. Cell Phone" << endl << "H. Home Phone\n";
        cin >> choice;
        switch (choice){
            case 'C':
                change_pref("Cellphone");
                break;
            case 'H':
                change_pref("HomePhone");
                break;
        }
    }
    void change_pref(string p) {//mutator for pref number
        pref = p;
    }
    string get_pref() { //accessor for pref number
        return pref;
    }
    
    
    
    
private: //data types
    string fname, lname, studentid, status, gterm, campus, degree, pref, homephonenumber, gyear, cellphone;
    double gpa;
    char gender, mi;
    int credits, month, day, year;
    
};


int main() {
    Undergraduate s1("Mario", "Merendino", 'J', 01, 20, 1996); //initializes the name and DOB variables.
    cout << s1.get_fname() << " " << s1.get_mi() << " " <<  s1.get_lname() << endl;//Display name
    cout << s1.get_month()<< "/" << s1.get_day() << "/" << s1.get_year() << endl;//display DOB
    
   	s1.setfname();//Set First name
    s1.setlname();//Set Last nameg    s1.setmi();//set Middle initial
    s1.setbirthday();//set birthday
    s1.setgender();//set gender
    s1.setstudentid();//set Students id
    s1.setstatus();//Sets Students current status
    s1.setgterm();//sets Students grad year
    s1.setcampus();//Sets the students campus
    s1.setdegree();//sets the students degree
    s1.setcredits();//sets the amt of credits
    s1.setgpa();//sets GPA
    s1.sethomephonenumber();//sets home phone
    s1.setcellphone();//sets cell
    s1.setpref();//sets preference
    cout << "Students Name: " << s1.get_fname() << " " << s1.get_mi() << " " << s1.get_lname() << endl;//Display Name
    cout << "Students Birthday: " << s1.get_month()<< "/" << s1.get_day() << "/" << s1.get_year() << endl;//Dispaly DOB
    cout << "Gender: " << s1.get_gender() << endl;// Display gender
    cout << "Student ID is: " << s1.get_studentid() << endl;//Display ID
    cout << "Current Status of Student is: " << s1.get_status() << endl;//Display Status
    cout << "Student is expected to Graduate in the  "<< s1.get_gterm() << "of" <<  endl;//Display GradYear
    cout << "Current Campus: " << s1.get_campus() << endl;//Display Campus
    cout << "Current Degree: " << s1.get_degree() << endl;//Display Degree
    cout << "Number of credits earned: " << s1.get_credits() << endl;//displays credits
    cout << "GPA of student: " << s1.get_gpa() << endl;//Display GPA
    cout << "Cellphone Number: " << s1.get_cellphone() << endl;//display cell
    cout << "Home Phone Number: " << s1.get_homephonenumber() << endl;//Display Homenumber
    cout << "Preferred Phone: " << s1.get_pref() << endl;//display preference
}
