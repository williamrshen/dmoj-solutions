import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


//  2014 j2
        int v = sc.nextInt();
        int ACount = 0;
        int BCount = 0;

        String votes = sc.next();

        for (int i=0; i<v; i++){
            String result = votes.substring(i, i+1);
            if (result.equals("A")) {
                ACount ++;
            } else if (result.equals("B")) {
                BCount ++;
            }
        }

        if (ACount > BCount) {
            System.out.println("A");
        } else if (BCount > ACount) {
            System.out.println("B");
        } else {
            System.out.println("Tie");
        }






    }
}