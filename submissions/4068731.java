import java.util.*;
import java.io.*;

public class Main {


    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PriorityQueue<Integer> ok = new PriorityQueue<>();
        for (int i = 0; i < 3; i ++) ok.add(sc.nextInt());
        ok.poll();
        System.out.println(ok.poll());
    }

}