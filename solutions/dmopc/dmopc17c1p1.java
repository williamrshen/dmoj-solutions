import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        boolean[] col = new boolean[c];
        boolean[] row = new boolean[r];
        for (int i = 0; i < r; i ++) {
            char[] a = sc.next().toCharArray();
            for (int h = 0; h < a.length; h ++) {
                if (a[h] == 'X') {
                    col[h] = true;
                    row[i] = true;
                }
            }
        }
        int q = sc.nextInt();
        for (int i = 0; i < q; i ++) {
            int x = sc.nextInt()-1;
            int y = sc.nextInt()-1;
            if (col[x] || row[y]) System.out.println("Y");
            else System.out.println("N");
        }

    }
}