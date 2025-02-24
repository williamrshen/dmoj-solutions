import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String o = "Ordinary pair";
        String m = "Mirrored pair";

        System.out.println("Ready");

        while (true) {
            String line = sc.nextLine();

            if (line.equals("  ")) {
                break;
            }

            if (line.equals("pq") || line.equals("qp") || line.equals("bd") || line.equals("db")) System.out.println(m);
            else System.out.println(o);
        }
    }
}