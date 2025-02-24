import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int count = 0;
        Set<String> items = new HashSet<>();
        sc.nextLine();
        for (int i = 0; i < n; i ++) items.add(sc.nextLine());
        for (int j = 0; j < m; j ++) {
            int t = sc.nextInt();
            sc.nextLine();
            boolean a = true;
            for (int i = 0; i < t; i ++) {
                String item = sc.nextLine();
                if (items.contains(item) == false) {
                    a = false;
                }
            }
            if (a) count ++;
            else continue;
        }
        System.out.println(count);
    }
}