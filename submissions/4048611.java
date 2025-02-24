import java.util.*;
import java.io.*;
public class BoosterCushions {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static long[] reverse(long[] arr) {
    	long temp = 0;
    	int lower = 0, upper = arr.length - 1;
    	while(lower < upper) {
    		temp = arr[lower];
    		arr[lower] = arr[upper];
    		arr[upper] = temp;
    		lower++;
    		upper--;
    	}
    	return arr;
    }
	public static void main(String[] args) throws IOException{
		int m = readInt(), n = readInt(), k = readInt();
		long ans = 0;
		long[] h = new long[k];
		for(int i = 0; i < k; i++) {
			h[i] = readLong();
		}
		Arrays.sort(h);
//		for(int i = 0; i < k / 2; i++) {
//			long temp = h[i];
//			h[i] = h[(int)k - i - 1];
//			h[(int)k - i - 1] = temp;
//		}
		h = reverse(h);
		int cols = (int) Math.ceil((double)k / m);
		int temp = Math.min(cols, n);
		for(int i = 0; i < temp; i++) {
			for(int j = 1; j < m; j++) {
				if(temp < k) {
					ans += h[i] - h[temp] + j;
					temp++;
				}
				else break;
			}
		}
		System.out.println(ans);

	}
	static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}