import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        
        int s = sc.nextInt();
        int r = sc.nextInt();
        
        if (s*s > 3.14*r*r) {
            System.out.println("SQUARE");
        } else {
            System.out.println("CIRCLE");
        }
    }
}