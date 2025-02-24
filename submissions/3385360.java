import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main (String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int [] d = new int[4];
        for (int i = 0; i < 4; i ++) {
            d[i] = sc.nextInt();
        }

        System.out.print(0 + " ");
        System.out.print(d[0] + " ");
        System.out.print(d[0] + d[1] + " ");
        System.out.print(d[0] + d[1] + d[2] + " ");
        System.out.println(d[0] + d[1] + d[2] + d[3] + " ");

        System.out.print(d[0] + " ");
        System.out.print(0 + " ");
        System.out.print(d[1] + " ");
        System.out.print(d[1] + d[2] + " ");
        System.out.println(d[1] + d[2] + d[3] + " ");

        System.out.print(d[0] + d[1] + " ");
        System.out.print(d[1] + " ");
        System.out.print(0 + " ");
        System.out.print(d[2] + " ");
        System.out.println(d[2] + d[3] + " ");

        System.out.print(d[0] + d[1] + d[2] + " ");
        System.out.print(d[1] + d[2] + " ");
        System.out.print(d[2] + " ");
        System.out.print(0 + " ");
        System.out.println(d[3] + " ");

        System.out.print(d[0] + d[1] + d[2] + d[3] + " ");
        System.out.print(d[1] + d[2] + d[3] + " ");
        System.out.print(d[2] + d[3] + " ");
        System.out.print(d[3] + " ");
        System.out.println(0 + " ");


    }

}