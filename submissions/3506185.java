import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = sc.nextInt();
        int m = sc.nextInt();
        int crash = 0;

        for (int i = 0; i < m; i ++) {
            if (sc.nextInt() >= n) {
                crash ++;
            }
        }
        System.out.println(crash);

    }
}