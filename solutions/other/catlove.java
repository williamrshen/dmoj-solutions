import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int c = 0;
        int d = 0;

        for (int i = 0; i < n; i ++) {
            if (br.readLine().equals("cats")) {
                c++;
            } else {
                d++;
            }
        }
        if (c>d) {
            System.out.println("cats");
        } else if (c == d){
            System.out.println("equal");
        } else {
            System.out.println("dogs");
        }
    }
}