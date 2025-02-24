import java.math.*;
import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String one = sc.next();
        String two = sc.next();

        if (one.equals("RED")) {
            if (two.equals("BLUE")) {
                System.out.print("WHITE");
            } else {
                System.out.print("BLUE");
            }
        } else if(one.equals("BLUE")) {
            if (two.equals("RED")) {
                System.out.print("WHITE");
            } else {
                System.out.print("RED");
            }

        } else {
            if (two.equals("BLUE")) {
                System.out.print("RED");
            } else {
                System.out.print("BLUE");
            }

        }
    }
}