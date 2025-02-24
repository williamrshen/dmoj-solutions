import java.util.*;
public class Student {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (true) {
      //input one single line
      int N = sc.nextInt();
      if (N==0) break;
      if (N==1) {
        sc.nextInt();
        System.out.println(0);
        continue;
      }
      int[] A = new int[N];
      for (int i=0; i<N; i++) {
        A[i] = sc.nextInt();
      }

      int[] diff = new int[N-1];
      for (int i=0; i<N-1; i++) {
        diff[i] = A[i+1]-A[i];
      }
      for (int L=1; L<=N-1; L++) {   //what is the cycle length
        boolean cycle = true;
        for (int i=0; i<N-1-L; i++) {
          if (diff[i]!=diff[i+L]) {
            cycle = false;  //Exception
            break;
          }
        }
        if (cycle) {
          System.out.println(L);
          break;
        }
      }
    }
  }
}