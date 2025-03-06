import java.util.*;
import java.io.*;

public class Main {


    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String [] mangas = new String[n];
        double [] costs = new double[n];

        for (int i = 0; i < n; i ++) {
            mangas[i] = sc.next();
            
            double price = sc.nextDouble();

            price*=100;
            costs[i] = price;
        }
        double best = -1;
        int bestIndex = -1;

        for (int i = 0;i < n; i ++) {
            if (costs[i] > best) {
                best = costs[i];
                bestIndex = i;
            }
        }
        System.out.print(mangas[bestIndex]);


    }
}