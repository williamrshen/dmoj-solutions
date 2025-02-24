import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
      int k = sc.nextInt();    
      String word = sc.next();  
      for (int i = 0; i <word.length(); i ++) {
        char c = word.charAt(i);   
        int s = 3*(i+1)+k; 
        int result = c - s;
        if (result < 'A') {
          result += 26;
        }
        char letter = (char)result;
        System.out.print(letter);
      }
     
    }
}