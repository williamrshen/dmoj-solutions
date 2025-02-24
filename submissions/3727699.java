import java.io.IOException;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        for (int q = 0; q < 10; q ++) {
            int n = sc.nextInt();
            Set<String> unique = new HashSet<>();
            for (int i = 0; i < n; i ++) {
                unique.add(ok(sc.next()));
            }
            System.out.println(unique.size());
        }
    }

    public static String ok (String s) {
        char[] a = s.toLowerCase().toCharArray();
        String l = new String();
        int at = s.indexOf("@");

        for (int i = 0; i < a.length; i ++) {
            String yes = String.valueOf(a[i]);
            if (a[i] == '+') {
                i = at;
                l = l + "@";
                continue;
            } else if (a[i] == '.' && i < at) {
                continue;
            } else {
                l = l + yes;
            }
        }
        return l;
    }
}