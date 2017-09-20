import java.io.*;
import java.net.*;
import java.util.*;

public class client{
    public static void main(String[] args){
        try{
            Socket sock = new Socket(args[0], Integer.valueOf(args[1]));
            // reading from keyboard
            Scanner userInput = new Scanner(System.in);
            // sending to client (pwrite object)
            OutputStream ostream = sock.getOutputStream(); 
            PrintWriter pwrite = new PrintWriter(ostream, true);

            // receiving from server
            InputStream istream = sock.getInputStream();
            BufferedReader receiveRead = new BufferedReader(new InputStreamReader(istream));

            System.out.println("Sending messages to Host: " + args[0]);
            System.out.println("On port: " + args[1]);

            String receiveMessage, sendMessage;        
            Boolean exit = false;       
            while(!exit){
                sendMessage = userInput.nextLine(); 
                pwrite.println("Client" + getTime() + ": " + sendMessage); 
                if((receiveMessage = receiveRead.readLine()) != null){    
                    System.out.println(receiveMessage); 
                } 
                else if(receiveMessage == null){  

                }         
            }
        }
        catch(NumberFormatException e){
            System.out.println("Error: correct usage 'java client [Server IP] [port]'");
        }
        catch(ConnectException e){
            System.out.println(e.getMessage());
            System.out.println("Error: Ensure Server is up and on the same port");
        }
        catch(Exception e){
            System.out.println("Error: correct usage 'java client [Server IP] [port]'");
        }            
    }
    public static String getTime(){
        String currentTimestamp = new java.sql.Timestamp(Calendar.getInstance().getTime().getTime()).toString();
        return currentTimestamp;
    }                    
}                        