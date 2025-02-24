import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


//  2020 j2
        int p = sc.nextInt();
        int n = sc.nextInt();
        int r = sc.nextInt();
        int total = 0;
        int days = 0;



        while (total <= p) {
            total += n;
            n *= r;
            days+=1;
        }

        System.out.println(days - 1);
    }
}