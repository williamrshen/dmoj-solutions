import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int [] songs = new int [n];

        for (int i = 0; i < n; i ++) {
            int m = sc.nextInt();
            int s = sc.nextInt();

            s += m*60;
            songs[i] = s;
        }

        Arrays.sort(songs);

        int tm = sc.nextInt();
        int ts = sc.nextInt();
        ts += tm*60;

        int total = 0;
        int index = 0;
        int count = 0;

        while (true) {
            if (index == n) {
                break;
            }
            total += songs[index];
            index ++;
            if (total > ts) {
                break;
            } else {
                count ++;
            }

        }

        System.out.println(count);

    }
}