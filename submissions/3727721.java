import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import static java.lang.Character.isLetterOrDigit;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        for (int q = 0; q < 10; q ++) {
            int n = sc.nextInt();

            Set<String> unique = new HashSet<>();
            for (int j = 0; j < n; j ++) {
                String[] email = sc.next().toLowerCase().split("@");
                char[] before = email[0].toCharArray();
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < before.length; i++) {
                    if (before[i] == '+') break;
                    if (isLetterOrDigit(before[i])) {
                        sb.append(before[i]);
                    }
                }
                unique.add(sb + "@" + email[1]);
            }
            System.out.println(unique.size());
        }
    }
}