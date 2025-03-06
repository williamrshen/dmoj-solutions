import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int longest = 0;

        for (int i = 0; i < n; i ++) {
            int dif = Math.abs(sc.nextInt()-sc.nextInt());
            if (dif > longest) {
                longest = dif;
            }
        }
        System.out.print(longest);

    }
}