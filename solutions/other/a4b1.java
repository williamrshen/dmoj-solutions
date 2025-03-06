import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int [] values = new int [n];

    for (int i = 0; i < n; i ++) {
      values[i] = sc.nextInt();
    }

    Arrays.sort(values);
    for (int i = 0; i < n; i ++) {
      System.out.println(values[i]);
    }
  }
}