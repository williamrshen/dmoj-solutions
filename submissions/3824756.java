import java.lang.reflect.Array;
import java.util.*;


public class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i ++) a[i] = sc.nextInt();
        Arrays.sort(a);
        List<Character> answer = new ArrayList<>();
        List<Integer> p = new ArrayList<>();
        for (int i = 0, j = n - 1; i <= j; i ++, j --) {
            p.add(a[i]);
            p.add(a[j]);
            if (i != j) {
                answer.add('B'); answer.add('S');
            }
            else answer.add('E');
        }
        for (int i = 0; i < n; i ++) {
            System.out.print(p.get(i) + (i == n-1? "\n" : " "));
        }
        for (char c : answer) System.out.print(c);
        System.out.println();
    }
}