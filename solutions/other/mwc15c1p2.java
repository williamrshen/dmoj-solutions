import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception {
//        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String firstLine = br.readLine();
        String[] fl = firstLine.split(" ");

        int n = Integer.parseInt(fl[0]);
        int m = Integer.parseInt(fl[1]);

        String [][] design = new String [n][m];

        int maxRow = -1;
        int maxCol = -1;
        int minRow = 100000;
        int minCol = 100000;


        for (int i = 0; i < n; i ++) {
            String thisLine = br.readLine();
            String [] tl = thisLine.split(" ");

            for (int j = 0; j < m; j ++) {

                design[i][j] = tl[j];


                if (tl[j].equals("*")) {
                    if (j > maxCol) {
                        maxCol = j;
                    }
                    if (j < minCol) {
                        minCol = j;
                    }
                    if (i > maxRow) {
                        maxRow = i;
                    }
                    if (i < minRow) {
                        minRow = i;
                    }
                }

            }

        }
        for (int i = minRow; i <= maxRow; i ++) {
            for (int j = minCol; j <= maxCol; j ++) {
                System.out.print(design[i][j] + " ");
            }
            System.out.println("");
        }


    }
}