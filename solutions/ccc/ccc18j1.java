import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main (String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);

//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int one = sc.nextInt();
        int two = sc.nextInt();
        int three = sc.nextInt();
        int four = sc.nextInt();

        if (two == three) {
            if (one == 8 || one == 9) {
                if (four == 8 || four == 9) {
                    System.out.println("ignore");
                } else {
                    System.out.println("answer");
                }
            } else {
                System.out.println("answer");
            }
        } else {
            System.out.println("answer");
        }



    }

}