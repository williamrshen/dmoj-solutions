import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        String t = sc.next();
        char [] ss = s.toCharArray();
        char [] tt = t.toCharArray();


        int index = 0;
        int pre = 0;

        while (true) {
            if (index >= ss.length || index >= tt.length) {
                break;
            }
            if (ss[index] != tt[index]) {
                break;
            }
            
            pre ++;
            index ++;
        }

        pre *= 2;

        System.out.println(ss.length + tt.length - pre);
    }
}