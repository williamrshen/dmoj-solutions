import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String o = "Ordinary pair";
        String m = "Mirrored pair";

        System.out.println("Ready");

        while (true) {
            String line = sc.nextLine();

            if (line.equals("  ")) {
                break;
            }

            char[] a = line.toCharArray();

            if (a[0] == 'b') {
                if (a[1] == 'd') {
                    System.out.println(m);
                } else {
                    System.out.println(o);
                }
            } else if (a[0] == 'd') {
                if (a[1] == 'b') {
                    System.out.println(m);
                } else {
                    System.out.println(o);
                }
            } else if (a[0] == 'p') {
                if (a[1] == 'q') {
                    System.out.println(m);
                } else {
                    System.out.println(o);
                }
            } else if (a[0] == 'q') {
                if (a[1] == 'p') {
                    System.out.println(m);
                } else {
                    System.out.println(o);
                }
            } else {
                System.out.println(o);
            }
        }
    }
}