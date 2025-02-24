import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int T = sc.nextInt();
        for (int i = 0; i<T; i++) {
            long s1 = sc.nextLong();
            long s2 = sc.nextLong();
            long s3 = sc.nextLong();
            long [] a = {s1,s2,s3};
            Arrays.sort(a);
            if (a[0]*a[0]+a[1]*a[1] == a[2]*a[2]) {
                System.out.println("R");
            }   else if (a[0]*a[0]+a[1]*a[1] > a[2]*a[2]) {
                System.out.println("A");
            }   else {
                System.out.println("O");
            }
        }
    }

//        Scanner sc= new Scanner(System.in);
//
//        long t = sc.nextInt();
//
//        for (long i = 0; i < t; i ++) {
//            long one = sc.nextLong();
//            long two = sc.nextLong();
//            long three = sc.nextLong();
//
//            List<Long> co = Stream.of(one, two, three).collect(Collectors.toList());
//
//            Collections.sort(co);
//            long a = co.get(0);
//            long b = co.get(1);
//            long c = co.get(2);
//            if (a*a + b*b > c*c) {
//                System.out.println("A");
//            } else if(a*a + b*b < c*c) {
//                System.out.println("O");
//            } else {
//                System.out.println("R");
//            }
//        }
//    }
}