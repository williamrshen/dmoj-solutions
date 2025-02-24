import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
      int K = scanner.nextInt();
      String str = scanner.next();
      for (int i = 0; i < str.length(); i++){
          char curr = str.charAt(i);
          int S = 3 * (i+1) + K;
          curr = (char) (curr-S);
          //double check the curr if <'A' 
          if (curr < 'A') {
              curr = (char) (curr + 26);
          }
          System.out.print(curr);
      }
     
    }
}