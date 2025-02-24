import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


//  2014 j3
        int n = sc.nextInt();

        int A = 100;
        int D = 100;

        for (int i=1; i<=n; i++){
            int ARoll = sc.nextInt();
            int DRoll = sc.nextInt();

            if (ARoll > DRoll) {
                D -= ARoll;
            } else if (DRoll > ARoll) {
                A -= DRoll;
            }
        }
        System.out.println(A);
        System.out.println(D);

    }
}