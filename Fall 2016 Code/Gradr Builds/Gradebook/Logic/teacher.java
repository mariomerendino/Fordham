package Logic;
import java.util.*;
import java.io.*;

public class teacher{
    String password;
    static String username;
    String firstName;
    String lastName;
    public teacher(){

    }
    public void setuserName(String n){
        username = n;
    }
    public void setfirstName(String n){
        firstName = n;
    }
    public void setlastName(String n){
        lastName = n;
    }
    public static String getuserName(){
        return username;
    }
    public String getfirstName(){
        return firstName;
    }
    public String getlastName(){
        return lastName;
    }
    public void setpassword(String p){
        password = p;
    }
    public String getpassword(){
        return password;
    }
}