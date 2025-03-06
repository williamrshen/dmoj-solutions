import java.util.*;
import java.io.*;

public class Main {


    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        String e = sc.next();
        String motto = sc.next();

        for (int i = 0; i <= 25; i ++) {
            String original = "";
            for (int j = 0; j < e.length(); j ++) {
                char c = (char)(e.charAt(j) - i);
                if (c < 'a') {
                    c = (char)(c+26);
                }
                original += c;
            }
            if (original.contains(motto)) {
                System.out.println(i);
                System.out.println(original);
                break;
            }
        }
    }
}