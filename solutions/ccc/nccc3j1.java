import java.util.Arrays;
import java.util.Scanner;

public class Main {



    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int count = 0;
        int n = sc.nextInt();
        for (int i = 0; i < n; i ++) {
            int a = sc.nextInt();
            if (a != 0) count += a;
        }
        System.out.println(count);
    }
}