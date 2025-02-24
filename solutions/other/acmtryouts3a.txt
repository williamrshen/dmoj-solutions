import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int g = sc.nextInt();

        for (int i = 0; i < g; i ++) {

            int n = sc.nextInt();
            int [] jaja = new int[n];

            for (int j = 0; j < n; j ++) {
                jaja[j] = sc.nextInt();
            }

            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;

            for (int k = 0; k < n; k ++) {
                if(jaja[k] > max) {
                    max = jaja[k];
                }
                if(jaja[k] < min) {
                    min = jaja[k];
                }
            }
            System.out.println(min + " " + max);
        }
    }
}