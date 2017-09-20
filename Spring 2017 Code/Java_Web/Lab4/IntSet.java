import java.util.*; 

public class IntSet{
    public Vector<Integer> data = new Vector<Integer>();
    
    public IntSet(){

    }
    public boolean includes(int x){
        if(data.contains(x))
            return true;
        else
            return false;
    }
    public int size(){
        return data.size();
    }
    public void add(int x){
        data.add(x);

    }
    public void remove(int x) throws IllegalArgumentException{
        int index = data.indexOf(x);
        if(index == -1)
            throw new IllegalArgumentException();
        else{
            data.remove(index);
        }
            
    }
    public String listAsString(){
        String list = new String(" ");
        for(int i = 0; i < data.size(); i++){
            list = list + " " + data.get(i).toString();
        }
        return list;
    
    }
}