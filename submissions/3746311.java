import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        LinkedList<Double> streams = new LinkedList<>();

        for (int i = 0; i < N; i++) {
            streams.add(sc.nextDouble());
        }

        while (true) {
            int instruction = sc.nextInt();
            if (instruction==77) {
                break;
            } else if (instruction==99) {
                int split = sc.nextInt()-1;
                int percent = sc.nextInt();
                double totalFlow = streams.get(split);
                double newFlow = totalFlow * percent / 100.0;
                streams.set(split, newFlow);
                streams.add(split+1, totalFlow - newFlow);
            } else if (instruction==88) {
                int merge = sc.nextInt()-1;
                double totalFlow = streams.get(merge) + streams.get(merge+1);
                streams.set(merge, totalFlow);
                streams.remove(merge+1);
            }
        }
        for (double f : streams) {
            System.out.print(Math.round(f) + " ");
        }
    }
}