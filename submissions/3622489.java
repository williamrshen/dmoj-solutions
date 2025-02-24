import java.math.*;
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();

        for (int i = 0; i < b-a+1; i ++) {

            int u = a+i;
            Set<Integer> pf = new HashSet<>();


            while (u%2 == 0) {
                u = u/2;
                pf.add(2);
            }


            for (int k = 3; k <= u; k += 2) {

                if (k > Math.sqrt(u)) {
                    pf.add(u);
                    break;
                }

                while (u%k == 0) {
                    u = u/k;
                    pf.add(k);
                }
            }
            System.out.println(pf.size());
        }
    }
}