import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        String type[] = new String[t];
        Map<String, LinkedList<Integer>> types = new HashMap<>();
        for (int i = 0; i < t; i ++) {
            type[i] = sc.next();
            types.put(type[i], new LinkedList<>());
        }
        int n = sc.nextInt();
        for (int i = 0; i < n; i ++) {
            String s = sc.next();
            types.get(s).add(i + 1);
        }
        for (int i = 0; i < t; i ++) {
            for (int x : types.get(type[i])) {
                System.out.println(x);
            }
        }

    }
}