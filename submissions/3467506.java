import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {

        Scanner sc= new Scanner(System.in);

        long t = sc.nextInt();

        for (long i = 0; i < t; i ++) {
            long one = sc.nextLong();
            long two = sc.nextLong();
            long three = sc.nextLong();

            long [] co = {one, two, three};

//            List<Long> co = Stream.of(one, two, three).collect(Collectors.toList());

//            Collections.sort(co);
            Arrays.sort(co);
            long a = co[0];
            long b = co[1];
            long c = co[2];
            if (a*a + b*b > c*c) {
                System.out.println("A");
            } else if(a*a + b*b < c*c) {
                System.out.println("O");
            } else {
                System.out.println("R");
            }
        }
    }
}