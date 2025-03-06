import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


//  2014 j1

        int angle1 = sc.nextInt();
        int angle2 = sc.nextInt();
        int angle3 = sc.nextInt();

        if (angle1==angle2 && angle2==angle3 && angle3==60) {
            System.out.println("Equilateral");
            return;
        } else if (angle1+angle2+angle3 == 180) {
            if (angle1 == angle2 || angle2==angle3 || angle3== angle1) {
                System.out.println("Isosceles");
                return;
            } else {
                System.out.println("Scalene");
                return;
            }
        } else {
            System.out.println("Error");
        }





    }
}