import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        int c = sc.nextInt();

        LinkedList<Integer> choreTimes = new LinkedList<Integer>();

        for (int i = 0; i < c; i++) {
            choreTimes.add(sc.nextInt());
        }

        Collections.sort(choreTimes);

        int totalTime = 0;
        int tasksCompleted = 0;

        int i = 0;

        while (totalTime <= t) {
            
            tasksCompleted ++;
            totalTime += choreTimes.get(i);
            i ++;
            if (totalTime > t) {
                tasksCompleted --;
            }
        }
        System.out.println(tasksCompleted);





    }
}