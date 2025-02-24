import java.util.*;

public class Solution {
 
  public static void main(String[] args) {
      //Ivan
      Scanner sc = new Scanner(System.in);
      int A = 100;
      int D = 100;
      int N = sc.nextInt();
      for (int i=0; i<N; i++) {
          int Ap = sc.nextInt();
          int Dp = sc.nextInt();
        
          if (Ap>Dp) {
             D -= Ap; 
          }  else if(Dp>Ap){
             A -= Dp;
          }
      }
      System.out.println(A);
      System.out.println(D);
      sc.close();
  }

}