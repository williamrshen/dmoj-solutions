import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int three1 = sc.nextInt();
        int two1 = sc.nextInt();
        int one1 = sc.nextInt();

        int three2 = sc.nextInt();
        int two2 = sc.nextInt();
        int one2 = sc.nextInt();

        int total1 = three1*3 + two1*2 + one1;
        int total2 = three2*3 + two2*2 + one2;

        if (total1 > total2) {
            System.out.println("A");
        } else if (total2 > total1) {
            System.out.println("B");
        } else {
            System.out.println("T");
        }


    }
}