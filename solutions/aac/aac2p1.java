import java.math.*;
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String chant = sc.next();
        char [] c = chant.toCharArray();
        int odd = 0;

//        'a' = 97

        for (int i = 1; i <= 26; i ++) {

            int counter = 0;

            for (int k = 0; k < c.length; k ++) {
                if (c[k] == i+96) {
                    counter ++;
                }
            }

            if (counter%2 != 0) {
                odd ++;
            }

        }

        System.out.println(Math.max(1, odd));


    }
}