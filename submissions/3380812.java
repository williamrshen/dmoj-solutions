import java.util.*;
import java.io.*;    //1

public class Main {
    public static void main (String args[]) {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        int y = sc.nextInt();

        if (x == Math.abs(x)) {
            if (y == Math.abs(y)) {
                System.out.println(1);
            } else {
                System.out.println(4);
            }
        } else {
            if (y == Math.abs(y)) {
                System.out.println(2);
            } else {
                System.out.println(3);
            }
        }



    }

}