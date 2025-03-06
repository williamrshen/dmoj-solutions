import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        int Y = sc.nextInt();
        int Z = sc.nextInt();
        int test = 1;

        for (int i = 1; i <= 10000; i++) {
            test += 1;
            if ((test % X == 0) && (test % Y == Z)) {
                System.out.println("YES");
                break;
            }
        }
        if (test>10000) {
            System.out.println("NO");
        }
    }
}