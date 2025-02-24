import java.io.*;
import java.util.*;



public class Main {
  static StringTokenizer st;
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  public static void main(String[] args) throws IOException {
    int[] xd = {1,2,4,7,8,11,13,14};
    int n = readInt();
    int num = (n - 1) / 8;
    System.out.println(xd[n - 8 * num - 1] + 15 * num);
  }

	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
  static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
  static long readLong () throws IOException {
		return Long.parseLong(next());
	}
}