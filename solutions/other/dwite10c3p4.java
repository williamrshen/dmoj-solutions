import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

import static java.lang.Integer.MAX_VALUE;

public class Main {
    public static void main(String args[]) throws Exception {
//        Scanner sc = new Scanner(System.in);


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int y = MAX_VALUE;

        for (int z = 0; z < 5; z ++) {

            char map[][] = new char[10][10];
            for (int i = 0; i < 10; i++) {
                map[i] = br.readLine().toCharArray();
            }

            int step[][] = new int[10][10];

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (map[i][j] == '.') {
                        step[i][j] = -1;
                    } else if (map[i][j] == 'F') {
                        step[i][j] = 0;
                    } else if (map[i][j] == 'T') {
                        step[i][j] = y;
                    }
                }
            }

            int sn = 0;
            while (true) {
                boolean found = false;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        if (step[i][j] == sn) {
                            found = true;
                            if (i+1 <= 9) {
                                if (step[i + 1][j] == y) {
                                    step[i + 1][j] = sn + 1;
                                }
                            }
                            if (i-1 >= 0) {
                                if (step[i - 1][j] == y) {
                                    step[i - 1][j] = sn + 1;
                                }
                            }
                            if (j+1 <= 9) {
                                if (step[i][j + 1] == y) {
                                    step[i][j + 1] = sn + 1;
                                }
                            }
                            if (j-1 >= 0) {
                                if (step[i][j - 1] == y) {
                                    step[i][j - 1] = sn + 1;
                                }
                            }

                        }
                    }

                }
                if (!found) {
                    break;
                }
                sn++;
            }
            boolean b = false;
            for (int i = 0; i < 10; i++) {

                for (int j = 0; j < 10; j++) {
                    if (step[i][j] == y) {
                        sn = 0;
                        b = true;
                        break;
                    }
                }
                if (b) break;
            }

            System.out.println(sn - 1);
            String waste = br.readLine();
        }

    }

}