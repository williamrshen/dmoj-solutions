import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);



        int x = sc.nextInt();
        int n = sc.nextInt();
        
        int one = x/n;
        int two = x%n;
        
        System.out.println(one + " " + two);

    }
}