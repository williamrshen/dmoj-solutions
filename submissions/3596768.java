import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int c = sc.nextInt();
        int v = sc.nextInt();
        String w = sc.next().toLowerCase();
        char [] word = w.toCharArray();;

        int vn = 0;
        int cn = 0;
        for (int i = 0; i < w.length(); i ++) {


            if (word[i] == 'y') {
                vn ++;
                cn ++;
            } else if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                vn ++;
                cn = 0;
            } else {
                cn ++;
                vn = 0;
            }

            if (vn > v || cn > c) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}