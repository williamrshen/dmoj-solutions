import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = sc.nextInt();
        int y = 0;
        int x = 0;

        for (int i = 0; i < n; i ++) {
            String dir = sc.next();
            int dis = sc.nextInt();

            if (dir.equals("North")) {
                y += dis;
            }
            if (dir.equals("South")) {
                y -= dis;
            }
            if (dir.equals("East")) {
                x += dis;
            }
            if (dir.equals("West")) {
                x -= dis;
            }

        }

        System.out.println(x + " " + y);
    }
}