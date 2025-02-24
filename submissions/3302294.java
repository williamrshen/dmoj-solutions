import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


//  2020 j1
        int s = sc.nextInt();
        int m = sc.nextInt();
        int l = sc.nextInt();

        int score = s + 2*m + 3*l;
        if (score >= 10) {
            System.out.println("happy");
        } else {
            System.out.println("sad");
        }

    }
}