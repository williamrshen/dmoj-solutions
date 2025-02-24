import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String a = sc.next();
        String s = sc.next();

        String [] at = a.split(":");
        String [] st = s.split(":");
        int [] AT = new int[3];
        int [] ST = new int[3];

        for (int i = 0; i < 3; i ++) {
            AT[i] = Integer.parseInt(at[i]);
            ST[i] = Integer.parseInt(st[i]);
        }

        AT[1] += AT[0]*60;
        AT[2] += AT[1]*60;
        



        ST[1] += ST[0]*60;
        ST[2] += ST[1]*60;
        

        System.out.println(ST[2] - AT[2]);



    }
}