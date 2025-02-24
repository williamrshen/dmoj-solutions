import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c = 0;
        int one = sc.nextInt();
        if (one == 1) c += 461;
        else if (one == 2) c += 431;
        else if (one == 3) c += 420;
        
        int two = sc.nextInt();
        if (two == 1) c += 100;
        if (two == 2) c += 57;
        if (two == 3) c += 70;
        
        int three = sc.nextInt();
        if (three == 1) c += 130;
        if (three == 2) c += 160;
        if (three == 3) c += 118;
    
        
        int four = sc.nextInt();
        if (four == 1) c += 167;
        if (four == 2) c += 266;
        if (four == 3) c += 75;
        
        System.out.println("Your total Calorie count is " + c + ".");
        
    }
}