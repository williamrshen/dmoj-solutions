import java.io.*;
import java.util.*;

public class Solution {
  public static void main(String[] args) throws IOException {
    int n = readInt();
    long d = readLong();
    int k = readInt(), x = readInt();
    double speed[] = new double[n + 1];
    for (int i = 1; i <= n; ++i) speed[i] = readLong();
    long p = readLong();
    double c = (double)(100 - x)/100;
    int count = 0;
    for (int i = 1; i <= n; ++i) {    //using i as index to read speed one by one from speed array
      
      //if you see any speed>=p you try to reduce the speed
      while (count <= k && speed[i] >= p) {
        speed[i] = Math.floor(speed[i]*c);  //reduce speed by *(100-X)/100
        ++count;
      }
    }
    if (count <= k) System.out.println("YES");  //use less or equals to k time to reduce the speed
    else System.out.println("NO");   //use more than k time to reduce the speed
  }
  
  
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;
  static String next() throws IOException {
    while (st == null || !st.hasMoreTokens())
      st = new StringTokenizer(br.readLine());
    return st.nextToken();
  }
  static int readInt() throws IOException {
    return Integer.parseInt(next());
  }
  static long readLong() throws IOException {
    return Long.parseLong(next());
  }
}