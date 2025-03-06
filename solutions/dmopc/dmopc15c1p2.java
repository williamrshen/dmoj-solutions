import java.util.*;
import java.io.*;

public class Main {


    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);



        int n = sc.nextInt();
        int l = sc.nextInt();
        int r = sc.nextInt();

        Integer [] soldiers = new Integer[n];
        int score = 0;

        for (int i = 0; i < n; i ++) {
            soldiers[i] = sc.nextInt();
        }
        Arrays.sort(soldiers, Collections.reverseOrder());


        for (int i = r-1; i < n; i += l) {
            score += soldiers[i];
        }
        System.out.println(score);
    }
}