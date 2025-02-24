import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long min = 1;
        long max = 2000000000;
        long mid = (min+max)/2;
        System.out.println(mid);
        while (true) {
            String a = sc.nextLine();
            if (a.equals("OK")) return;
            if (a.equals("FLOATS")) {
                max = mid - 1;
            }
            if (a.equals("SINKS")){
                min = mid + 1;
            }
            mid = (min+max)/2;
            System.out.println(mid);
            System.out.flush();
        }

    }
}