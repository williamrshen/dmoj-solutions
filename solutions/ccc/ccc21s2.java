import java.util.Scanner;

public class ccc21j5 {

  public static void main(String[] args)  {

    Scanner sc = new Scanner(System.in);
    int R = sc.nextInt();
    int C = sc.nextInt();
    int times = 0;
    int Snumber = sc.nextInt();
    int[] row = new int[R];
    int[] col = new int[C];
    for(int i=0; i<Snumber; i++) {
      String S =sc.next();
      int num = sc.nextInt();
      if(S.equals("R")) {
        row[num-1]+=1;
      } else {
        col[num-1]+=1;
      }
    }

    for(int i=0; i<R; i++) {
      for(int j=0; j<C; j++) {
        if((row[i]+col[j])%2 != 0) {
          times+=1;
        }
      }
    }

    System.out.println(times);

  }
}