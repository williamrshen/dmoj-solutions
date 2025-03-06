import java.util.*;
import java.io.*;
import java.math.*;

public class Main {


    public static int[] parent;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);


        long n = sc.nextInt();
        int m = sc.nextInt();

        int [] send = new int [m];
        int [] receive = new int [m];
        String [] name = new String [m];

        for (int i = 0; i < m; i ++) {
            send[i] = sc.nextInt();
            receive[i] = sc.nextInt();
            String waste = sc.nextLine();
            name[i] = sc.nextLine();
        }
        int y = sc.nextInt();

        for (int i = 0; i < m; i ++) {
//            if(send[i] == y) {
//                continue;
//            } else {
                if (receive[i] == y) {
                    System.out.println(name[i]);
                }
//            }

        }


    }

}