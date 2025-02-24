import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws Exception {
        LinkedList<Integer> tracker = new LinkedList<Integer>();
        int y = 0;

//        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String n = br.readLine();
            if (n.equals("99999")) {
                break;
            }
            char[] f = n.toCharArray();

            String a = String.valueOf(f[0]);
            String b = String.valueOf(f[1]);
            int ai = Integer.parseInt(a);
            int bi = Integer.parseInt(b);


            int ci = ai + bi;

            if (ci == 0) {
                if (tracker.get(y - 1) == 0) {
                    System.out.print("right ");
                    tracker.add(0);
                } else {
                    System.out.print("left ");
                    tracker.add(1);
                }
            } else if (ci % 2 == 0) {
                System.out.print("right ");
                tracker.add(0);
            } else if (ci % 2 == 1) {
                System.out.print("left ");
                tracker.add(1);
            }


            String one = String.valueOf(f[2]);
            String two = String.valueOf(f[3]);
            String three = String.valueOf(f[4]);
            System.out.println(one + two + three);
            y++;
        }


    }
}