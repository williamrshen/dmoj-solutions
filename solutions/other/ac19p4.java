import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int [] x = new int[n];
        int [] y = new int[n];
        int m = (int)5e4;
        Set<Integer> coords = new HashSet<>();
        for (int i = 0; i < n; i ++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
            coords.add(x[i] * m + y[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (coords.contains(x[i]*m + y[j]) && coords.contains(x[j]*m + y[i])) {
                    ans = Math.max(ans ,Math.abs(x[i] - x[j])*Math.abs(y[i] - y[j]));
                }
            }
        }
        System.out.println(ans);

    }

    public static class P {
        int x, y;
        public P (int a, int b) {
            this.x = a;
            this.y = b;
        }
    }
}