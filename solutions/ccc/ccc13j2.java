import java.math.*;
import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        char [] w = sc.next().toCharArray();

        for (int i = 0; i < w.length; i ++) {
            if (w[i] != 'X') {
                if (w[i] != 'O') {
                    if (w[i] != 'S') {
                        if (w[i] != 'H') {
                            if (w[i] != 'Z') {
                                if (w[i] != 'I') {
                                    if (w[i] != 'N') {
                                        System.out.println("NO");
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        System.out.println("YES");


    }

}