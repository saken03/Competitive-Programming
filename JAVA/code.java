import java.util.*;
 
public class code {
    public static void main(String[] args) {
        Pair<Integer, String> p = new Pair<Integer, String>(10, "Hello Geeks!");
       
        //printing the values of key and value pair separately
        System.out.println("The First value is :" + p.getKey());
        System.out.println("The Second value is :" + p.getValue());
    }
}