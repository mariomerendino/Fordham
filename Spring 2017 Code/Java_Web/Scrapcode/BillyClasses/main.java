import java.util.*;
import java.util.Scanner;

public class main{
    public static student list[] = new student[3];
    public static collegeStudent mario = new collegeStudent();
    public static collegeStudent billy = new collegeStudent();

    public static void main(String[] args){
        /*for(int i=0; i<3; i++){
            list[i] = new student();
            list[i].print();
            list[i].input();
        }
        for(int i=0; i<3; i++){
            list[i].print();
        }
        list[1].print();*/
        mario.input();
        mario.inputCollgeInfo();
        mario.print();
        mario.displayCollegeInfo();
        mario.equal(billy);
        mario.print();
    }
}