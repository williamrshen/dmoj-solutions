import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int a = 0;

        while (true) {
            String bool = sc.next();
            if (bool.equals("True") || bool.equals("False")) {

                if (a%2 == 0) {
                    System.out.println(bool);
                }

                if (a%2 == 1) {
                    if (bool.equals("True")) {
                        System.out.print("False");
                    }
                    if (bool.equals("False")) {
                        System.out.print("True");
                    }
                }

                break;
            }


            a ++;
        }


    }
}