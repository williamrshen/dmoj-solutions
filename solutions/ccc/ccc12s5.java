import java.io.IOException;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt(), c = sc.nextInt(), k = sc.nextInt();
        int[][] map = new int[r+1][c+1];
        for (int i = 0; i <= r; i ++) {
            for (int j = 0; j <= c; j ++) {
                if (i == 0 || j == 0) {
                    map[i][j] = 0;
                } else {
                    map[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < k; i ++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            map[x][y] = 0;
        }
        for (int i = 1; i <= r; i ++) {
            for (int j = 1; j <= c; j ++) {
                if (i == 1 && j == 1) {
                    map[1][1] = 1;
                } else {
                    if (map[i][j] == 0) {
                        continue;
                    } else {
                        map[i][j] = map[i-1][j] + map[i][j-1];
                    }
                }
            }
        }
        System.out.println(map[r][c]);
    }
}