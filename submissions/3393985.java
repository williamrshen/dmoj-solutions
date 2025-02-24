import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Scanner;

import static java.lang.Integer.MAX_VALUE;

public class Main {
    public static void main(String args[]) throws Exception {
//        Scanner sc = new Scanner(System.in);


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int N = 10;
        for (int i=0; i<5; i++) {
            char[][] map = new char[N][N];
            for (int j=0; j<N; j++) {
                map[j] = sc.next().toCharArray();
            }
            sc.next();
            int [][] step = new int[N][N];

            int startR = 0;
            int startC = 0;
            LinkedList<Integer> rq = new LinkedList<Integer>();
            LinkedList<Integer> cq = new LinkedList<Integer>();
            for (int j=0; j<N; j++) {
                for (int k=0; k<N; k++) {
                    if (map[j][k]=='F') {
                        startR = j;
                        startC = k;
                        step[startR][startC] = 0;
                        rq.add(startR);
                        cq.add(startC);
                    }  else if (map[j][k]=='.') {
                        step[j][k] = -1;
                    } else if (map[j][k]=='T') {
                        step[j][k] = MAX_VALUE;
                    }
                }
            }

            while (!rq.isEmpty()) {
                int r = rq.poll();
                int c = cq.poll();
                if (r-1>=0 && step[r-1][c]>step[r][c]+1) {
                    step[r-1][c]=step[r][c]+1;
                    rq.add(r-1);
                    cq.add(c);
                }
                if (r+1<N && step[r+1][c]>step[r][c]+1) {
                    step[r+1][c]=step[r][c]+1;
                    rq.add(r+1);
                    cq.add(c);
                }
                if (c-1>=0 && step[r][c-1]>step[r][c]+1) {
                    step[r][c-1]=step[r][c]+1;
                    rq.add(r);
                    cq.add(c-1);
                }
                if (c+1<N && step[r][c+1]>step[r][c]+1) {
                    step[r][c+1]=step[r][c]+1;
                    rq.add(r);
                    cq.add(c+1);
                }
            }
            int max = Integer.MIN_VALUE;
            boolean a = true;
            for (int j=0; j<N; j++) {
                for (int k=0; k<N; k++) {
                    if (step[j][k]== MAX_VALUE) {

                        a = false;
                    } else if (max<step[j][k]) {
                        max = step[j][k];
                    }
                }
            }
            if (a) {
                System.out.println(max);
            } else {
                System.out.println(-1);
            }
        }

    }

}