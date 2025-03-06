import java.util.*;
import java.io.*;

public class Main {


    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int d = sc.nextInt();

        for (int i = 0; i < d; i ++) {
            n*=k;
        }
        System.out.println(n);
    }

}