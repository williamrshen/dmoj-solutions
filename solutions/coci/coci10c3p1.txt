import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble(), b = sc.nextDouble(), c = sc.nextDouble(), d = sc.nextDouble();
        double max = -1;
        int ans = 0;
        for (int i = 0; i < 4; i ++) {
            double value = (a/c) + (b/d);
            // System.out.println(value);
            if (value > max) { 
                max = value;
                ans = i;
            }
            
            double ta = a;
            double tb = b;
            double tc = c;
            double td = d;
            b = ta;
            d = tb;
            c = td;
            a = tc;
        }
        System.out.println(ans);
    }
}