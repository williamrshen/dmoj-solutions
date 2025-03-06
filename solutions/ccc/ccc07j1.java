import java.util.*;
import java.io.*;

public class Main {


    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int [] p = new int [3];
        p[0] = sc.nextInt();
        p[1] = sc.nextInt();
        p[2] = sc.nextInt();
        
        Arrays.sort(p);
        
        System.out.println(p[1]);
    }

}