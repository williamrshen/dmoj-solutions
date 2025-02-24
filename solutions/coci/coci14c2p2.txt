import java.io.*;
import java.util.*;



public class Main {
  static StringTokenizer st;
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  public static void main(String[] args) throws IOException {
    int n = readInt();
    int[][] xd = new int[26][20];
    for (int i = 0; i < n + n - 1; i ++) {
      char[] hm = br.readLine().toCharArray();
      for (int j = 0; j < hm.length; j ++) {
        xd[hm[j] - 'a'][j] ++;
      }
    }
    for (int i = 0; i < 26; i ++) {
      for (int j = 0; j < 20; j ++) {
        // System.out.print(xd[i][j] + " ");
        // if (xd[i][j] % 2 == 1) {
        //   System.out.print((char)(i + 'a'));
        // }
      }
      // System.out.println();
    }
    for (int i = 0; i < 20; i ++) {
      for (int j = 0; j < 26; j ++) {
        if (xd[j][i] % 2 == 1) {
          System.out.print((char)(j + 'a'));
        }
      }
    }
  }
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
  static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
}