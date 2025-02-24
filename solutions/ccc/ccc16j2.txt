import java.util.Scanner;

public class Main {
    public static void main (String args[]) {

        Scanner sc = new Scanner(System.in);

        int [][] g = new int[4][4];
        int [] h = new int[8];
        boolean magic = true;

        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 4; j ++) {
                g[i][j] = sc.nextInt();
            }
        }


        for (int i = 0; i < 4; i ++) {
            int f = 0;
            for (int j = 0; j < 4; j ++) {
                f += g[i][j];
            }
            h[i] = f;
        }

        for (int i = 0; i < 4; i ++) {
            int f = 0;
            for (int j = 0; j < 4; j ++) {
                f += g[j][i];
            }
            h[i+4] = f;
        }

        for (int i = 0; i < 8; i ++) {
            for (int j = 0; j < 8; j ++) {
                if (h[i] != h[j]) {
                    magic = false;
                }
            }
        }

        if (magic) {
            System.out.println("magic");
        } else {
            System.out.println("not magic");
        }




    }

}