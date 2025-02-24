import java.util.Scanner;
import static java.lang.Character.isAlphabetic;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int m = 0; m < 5; m ++) {

            String line = sc.nextLine();
            String[] l = line.split(" ");
            int count = 0;
            for (int i = 0; i < l.length; i ++) {
                int length = real(l[i]);
                if (length > 3) {
                    count++;
                }
            }
            System.out.println(count);

        }
    }

    public static int real (String s) {
        String ok = s.toLowerCase();
        int size = ok.length();
        char[] a = ok.toCharArray();
        for (int i = 0; i < s.length(); i ++) {
            if (a[i] == '\'') return 0;
            else if (!isAlphabetic(a[i])) size --;
        }
        return size;
    }
}