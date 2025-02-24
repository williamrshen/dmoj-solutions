import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        int w = readInt(), h = readInt();
        int ww = readInt(), hh = readInt();
        int m = readInt();
        int[][] map = new int[h][w];
        for (int i = 0; i < hh; i ++) {
            for (int j = 0; j < ww; j ++) {
                map[i][j] = -1;
            }
        }
        for (int i = h - hh; i < h; i ++) {
            for (int j = w - ww; j < w; j ++) {
                map[i][j] = -1;
            }
        }
        for (int i = h - hh; i < h; i ++) {
            for (int j = 0; j < ww; j ++) {
                map[i][j] = -1;
            }
        }
        for (int i = 0; i < hh; i ++) {
            for (int j = w - ww; j < w; j ++) {
                map[i][j] = -1;
            }
        }

        // 1 = right, 2 = down, 3 = left, 4 = up
        int d = 1;
        int col = -1;
        int row = -1;
        for (int i = 0; i < w; i ++) {
            for(int j = 0; j < h; j ++) {
                if(map[i][j] == 0) {
                    row = i; col = j;
                    map[i][j] = 1;
                    break;
                }
            }
            if(col != -1 && row != -1) break;
        }
        // map[col][row] = -1;
        while (m > 0) {
          m --;
            if (d == 1) {
                if (row - 1 > -1 && map[row - 1][col] == 0) {
                    row --;
                    
                    map[row][col] = -1;
                    d = 4;
                }
                else if (col + 1 < w && map[row][col + 1] == 0) {
                    col ++;
                    
                    map[row][col] = -1;
                    d = 1;
                }
                else if (row + 1 < h && map[row + 1][col] == 0) {
                    row ++;
                    
                    map[row][col] = -1;
                    d = 2;
                }
                else if (col - 1 > -1 && map[row][col - 1] == 0) {
                    col --;
                    
                    map[row][col] = -1;
                    d = 3;
                }
            }
            else if (d == 2) {
                if (col + 1 < w && map[row][col + 1] == 0) {
                    col ++;
                    
                    map[row][col] = -1;
                    d = 1;
                }
                else if (row + 1 < h && map[row + 1][col] == 0) {
                    row ++;
                    
                    map[row][col] = -1;
                    d = 2;
                }
                else if (col - 1 > -1 && map[row][col - 1] == 0) {
                    col --;
                    
                    map[row][col] = -1;
                    d = 3;
                }
                else if (row - 1 > -1 && map[row - 1][col] == 0) {
                    row --;
                    
                    map[row][col] = -1;
                    d = 4;
                }


            }
            else if (d == 3) {
                if (row + 1 < h && map[row + 1][col] == 0) {
                    row ++;
                    
                    map[row][col] = -1;
                    d = 2;
                }
                else if (col - 1 > -1 && map[row][col - 1] == 0) {
                    col --;
                    
                    map[row][col] = -1;
                    d = 3;
                }
                else if (row - 1 > -1 && map[row - 1][col] == 0) {
                    row --;
                    
                    map[row][col] = -1;
                    d = 4;
                }
                else if (col + 1 < w && map[row][col + 1] == 0) {
                    col ++;
                    
                    map[row][col] = -1;
                    d = 1;
                }

            }
            else if (d == 4) {
                if (col - 1 > -1 && map[row][col - 1] == 0) {
                    col --;
                    
                    map[row][col] = -1;
                    d = 3;
                }
                else if (row - 1 > -1 && map[row - 1][col] == 0) {
                    row --;
                    
                    map[row][col] = -1;
                    d = 4;
                }
                else if (col + 1 < w && map[row][col + 1] == 0) {
                    col ++;
                    
                    map[row][col] = -1;
                    d = 1;
                }
                else if (row + 1 < h && map[row + 1][col] == 0) {
                    row ++;
                    
                    map[row][col] = -1;
                    d = 2;
                }
            }
            // for (int[] x : map) {
            //     for (int y : x) {
            //         System.out.print(y + " ");
            //     }
            //     System.out.println();
            // }
            // System.out.println();
        }
        System.out.println((col + 1) + "\n" + (row + 1));
    }


    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

}