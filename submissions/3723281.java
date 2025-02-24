import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);

        int n = sc.nextInt();
        String[] r = new String[n];
        for (int i = 0; i < n; i ++) {
            r[i] = sc.next();
        }
        int count = 0;
        for (int i = 0; i < n; i ++) {
            if (sc.next().equals(r[i])) count ++;
        }
        System.out.println(count);

    }
}