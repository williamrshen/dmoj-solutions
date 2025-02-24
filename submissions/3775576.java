import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int N = sc.nextInt();   //How many items
        int W = sc.nextInt();   //maximum weight

        long[][] memo = new long[2][W+1];
        int previousRow = 0;
        int row = 1;
        for (int i=1; i<N+1; i++) {
            int wi = sc.nextInt();
            int vi = sc.nextInt();
            for (int w=1; w<W+1; w++) {
                if (w>=wi) {
                    memo[row][w] = Math.max(memo[previousRow][w],  //did not choose i
                            memo[previousRow][w-wi]+vi);   //you choose i
                } else {
                    memo[row][w] = memo[previousRow][w];   //copy from previous row
                }
            }

            row = row^1;    //^ xor   if the same return 0  if not the same return 1
            previousRow = previousRow^1;
        }
        System.out.println(memo[previousRow][W]);


    }
}