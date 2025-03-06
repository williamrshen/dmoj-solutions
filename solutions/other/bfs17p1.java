import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int count = 0;

        for (int i = 0; i < n; i ++) {
            String s = sc.next();
            if (s.length() < 11) {
                count ++;
            }
        }
        System.out.println(count);
    }
}