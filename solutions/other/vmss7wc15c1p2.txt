import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();


        for (int i = 0; i < n; i ++) {

            int count = 0;

            int l = sc.nextInt();

            int [] cards = new int [l];

            for (int j = 0; j < l;j ++) {

                cards[j] = sc.nextInt();

            }
            boolean swap = false;


            do {

                swap = false;
                for (int h = 0; h < l-1; h ++) {




                    int thiss = cards[h];
                    int more = cards[h + 1];

                    if (more < thiss) {

                        cards[h] = more;
                        cards[h + 1] = thiss;
                        count++;
                        swap = true;

                    }

                }
            } while (swap);




        System.out.println(count);



        }


    }
}