import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = 1;
        while (true) {
            int x = sc.nextInt();
            if (x == 0) { System.out.println("You Quit!"); return; }
            if (a + x <= 100) a += x;
            if (a == 9) a = 34;
            else if (a == 40) a = 64;
            else if (a == 67) a = 86;
            else if (a == 99) a = 77;
            else if (a == 90) a = 48;
            else if (a == 54) a = 19;
            System.out.println("You are now on square " + a);
            if (a == 100) { System.out.println("You Win!"); return; }
        }
    }
}