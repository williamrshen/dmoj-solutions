import java.util.*;
import java.io.*;
import java.math.*;

public class Main {


    public static int[] parent;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String[] vetNames = new String[n];
        int [] vetScore = new int[n];

        for (int i = 0; i < n; i ++) {
            vetNames[i] = sc.next();
            vetScore[i] = sc.nextInt();
        }

        int q = sc.nextInt();


        for (int i = 0; i < q; i ++) {
            int skill = sc.nextInt();
            int adapt = sc.nextInt();

            LinkedList<Integer> a = new LinkedList<Integer>();

            for (int j = 0; j < n; j ++) {
                if (vetScore[j] >= skill && vetScore[j] <= skill+adapt) {
                    a.add(j);
                }
            }

            int lowest = 1000000;
            int index = 0;
            for (int k = 0; k < a.size(); k ++) {
                if (vetScore[a.get(k)] < lowest) {
                    lowest = vetScore[a.get(k)];
                    index = a.get(k);
                }
            }
            
            if (a.size() == 0) {
                System.out.println("No suitable teacher!");
            } else {
                System.out.println(vetNames[index]);
            }
        }



    }

}