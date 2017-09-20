import java.util.*;
public class maps{
    public static void main(String args[]){
        Map<String, String> map = new HashMap<String, String>();
        map.put("Mario", "Yo What up");
        map.put("John", "Shutup Mario");

        //System.out.println(map.get("Mario"));

        for (String s : map.keySet()){
            System.out.println(s + "->" + map.get(s));
        }
    }
}