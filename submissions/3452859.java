import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = sc.nextInt();
        int p = 5*i-400;
        System.out.println(p);
        if (p < 100) {
            System.out.println(1);
        } else if (p > 100) {
            System.out.println(-1);
        } else {
            System.out.println(0);
        }

    }
}