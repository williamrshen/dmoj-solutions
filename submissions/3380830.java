import java.util.*;
import java.io.*;    //1

public class Main {
    public static void main (String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int sum = 0;

        for (int i = 0; i <= k; i++) {
            sum += n;
            n *= 10;
        }
        System.out.println(sum);




    }

}