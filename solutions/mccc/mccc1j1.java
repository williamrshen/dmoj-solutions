import java.math.*;
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int [] numbers = {sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt()};

        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;


        for (int i = 0; i<4; i ++) {
            if (numbers[i]> max) {
                max = numbers[i];
            }
            if (numbers[i] < min) {
                min = numbers[i];
            }
        }

        System.out.println(min);
        System.out.println(max);
    }


}