import java.util.*;
import java.io.*;
import java.math.*;

public class Main {


    public static int[] parent;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);


//        int [][] array = new int [3][3];
//        int [][] map = new int [3][3];
//        int count = 1;
//
//        for (int i = 0; i < 3; i ++) {
//            for (int j = 0; j < 3; j ++) {
//                array[i][j] = sc.nextInt();
//                count ++;
//            }
//        }
//
//
//        //edges
//        map[0][0] = array[0][0];
//        for (int i = 1; i < 3; i ++) {
//            map[0][i] = array[0][i] + map[0][i-1];
//            map[i][0] = array[i][0] + map[i-1][0];
//        }
//
//        for (int i = 1; i < 3; i ++) {
//            for (int j = 1; j < 3; j ++) {
//                map[i][j] = array[i][j] + map[i-1][j] + map[i][j-1] - map[i-1][j-1];
//            }
//        }
//
//

        System.out.println((long)Math.pow(sc.nextInt(), sc.nextInt()));




    }

}