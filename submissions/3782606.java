import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt(), d = sc.nextInt();
        if (b > a) {
            if (d > c) {
                System.out.println("Go to the department store");
            } else {
                System.out.println("Go to the grocery store");
            }
        } else {
            if (d > c) {
                System.out.println("Go to the pharmacy");
            } else {
                System.out.println("Stay home");
            }
        }
    }
}