import java.math.*;
import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Map<Long, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i ++) {

            long s = sc.nextInt();
            Integer a = map.get(s);
            if (a == null) {
                a = 0;
            }

            map.put(s, a+1);

        }

        List<Integer> collect = map.values().stream().sorted().collect(Collectors.toList());
        
        if (collect.size() == 1) {
            System.out.println(n);
        } else {
            System.out.println((collect.get(collect.size() - 2)) + (collect.get(collect.size() - 1)));
        }

    }
}