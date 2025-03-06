import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = sc.nextInt();
        int total = 0;
        
        for (int i = 0; i < n; i ++) {
            total += Math.abs(sc.nextInt());
        }
        
        System.out.println(total);

    }
}