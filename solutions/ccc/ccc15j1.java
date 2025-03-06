import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int d = sc.nextInt();
        if (m > 2) System.out.print("After");
        else if (m < 2) System.out.print("Before");
        else {
            if (d > 18) System.out.print("After");
            else if (d < 18) System.out.print("Before");
            else System.out.print("Special");
        }
    }
}