import java.util.*;
import java.io.*;

public class Main {


    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String [] status = new String[n];
        int wa = 0;
        int waused = 0;
        int ir = 0;
        int irused = 0;

        for (int i = 0; i < n; i ++) {
            status[i] = sc.next();
            if (status[i].equals("WA")) {
                wa ++;
            }
            if (status[i].equals("IR")) {
                ir ++;
            }
        }

        for (int i = 0; i < n; i ++) {

            if (status[i].equals("AC")) {
                System.out.println("AC");
                continue;
            }

            if (status[i].equals("TLE")) {
                System.out.println("WA");
                continue;
            }

            if (status[i].equals("WA")) {
                waused ++;
                if (waused <= wa*3/10) {
                    System.out.println("AC");
                } else {
                    System.out.println("WA");
                }
                
            }

            if (status[i].equals("IR")) {
                irused ++;
                if (irused <= 10) {
                    System.out.println("AC");
                } else if (irused > 10 && irused <=20) {
                    System.out.println("WA");
                } else {
                    System.out.println("IR");
                }
                
            }
        }
    }

}