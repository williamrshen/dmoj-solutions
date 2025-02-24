import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main (String args[]) throws Exception {
//        Scanner sc = new Scanner(System.in);

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String ns = br.readLine();
        int n = Integer.parseInt(ns);

        String line1 = br.readLine();
        String line2 = br.readLine();

        int full = 0;

        for (int i = 0; i < n; i ++) {
            char e = line1.charAt(i);
            char f = line2.charAt(i);

            if (e == 'C' && f == 'C') {
                full ++;
            }
        }
        System.out.println(full);

    }

}