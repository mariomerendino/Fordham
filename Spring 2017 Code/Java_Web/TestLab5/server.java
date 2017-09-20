import java.io.*;
import java.net.*;
import java.util.*;


public class server{
      public static int port = 34;
      public static void main(String[] args) {
            try{
                  ServerSocket serverSocket = new ServerSocket(port);
                  System.out.println("Accepting incoming chats on port " + Integer.toString(serverSocket.getLocalPort())+ " !");
                  System.out.println("To Exit the Chat Type 'exit'");
                  Socket socket = serverSocket.accept( );                          
                  //reading from keyboard
                  Scanner userInput = new Scanner(System.in);
                  //sending to client
                  OutputStream ostream = socket.getOutputStream(); 
                  PrintWriter output = new PrintWriter(ostream, true);
                  //Gets input from client 
                  InputStream istream = socket.getInputStream();
                  BufferedReader receiveRead = new BufferedReader(new InputStreamReader(istream));
            
                  String receiveMessage, sendMessage;     
                  Boolean exit = false;
                  //Thread t1 = new Thread(new receiveThread(receiveRead));       
                  while(!exit)
                  {
                        //if there is a message that is recieved from the client it prints it. 
                        //if((receiveMessage = receiveRead.readLine()) != null){
                        //      System.out.println(receiveMessage);         
                        //}
                        sendMessage = userInput.nextLine(); 
                        if(sendMessage == "exit"){
                              exit = true;
                        }
                        else{
                              output.println("Server" + getTime() + ": " + sendMessage);             
                              output.flush();
                        }
                  } 
            }
            catch(Exception e){
                  System.err.println(e);
            }              
      }
    public static String getTime(){
        String currentTimestamp = new java.sql.Timestamp(Calendar.getInstance().getTime().getTime()).toString();
        return currentTimestamp;
    }                         
}