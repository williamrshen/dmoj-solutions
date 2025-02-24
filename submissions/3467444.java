import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);

        long n = sc.nextLong();
        long q = sc.nextLong();

        long [] count = new long[100001];
        for (int i = 0; i < n; i ++) {
            count[sc.nextInt()]++;
        }
        for (int i = 0; i < q; i ++) {
            long operation = sc.nextLong();
            int number =  sc.nextInt();

            if (operation == 1) {
                long f = count[number];
                count[number] = 0;
                count[number/2] += f;
                count[number - number/2] += f;
            } else {
                System.out.println(count[number]);
            }
        }

    }
}