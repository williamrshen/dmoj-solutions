import java.util.*;
import java.io.*;

public class Main {
        public static void main(String[] args) throws Exception {
            Scanner sc = new Scanner(System.in);

            String number = sc.next();

            String [] num = number.split("");

            int one = Integer.parseInt(num[0]);
            int two = Integer.parseInt(num[1]);
            int three = Integer.parseInt(num[2]);

            int four = Integer.parseInt(num[4]);
            int five = Integer.parseInt(num[5]);
            int six = Integer.parseInt(num[6]);

            int seven = Integer.parseInt(num[8]);
            int eight = Integer.parseInt(num[9]);
            int nine = Integer.parseInt(num[10]);
            int ten = Integer.parseInt(num[11]);

            int n1 = one + two + three;
            int n2 = four + five + six;
            int n3 = seven + eight + nine + ten;

            if (n1 == n2) {
                if (n2 == n3) {
                    System.out.println("Goony!");
                } else {
                    System.out.println("Pick up the phone!");
                }
            } else {
                System.out.println("Pick up the phone!");
            }


        }
    }