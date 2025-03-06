import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);

        int n = sc.nextInt();
        int h = -1;
        String wname = " ";

        for (int i = 0; i < n; i ++) {
            String name = sc.next();
            int bid = sc.nextInt();

            if (bid > h) {
               h = bid;
               wname = name;
            }
        }
        System.out.println(wname);
    }
}