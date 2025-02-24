import java.math.*;
import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int p = sc.nextInt()*sc.nextInt();
        for (int i = 0; i < 5; i ++) {
            System.out.print(sc.nextInt()-p + " ");
        }

    }
}