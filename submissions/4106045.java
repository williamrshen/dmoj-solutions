import java.util.Scanner;

public class uneven {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        long l = 1;
        long r = 2000000000;
        long mid = 1000000000;
        System.out.println(mid);
        System.out.flush();
        char f = in.nextLine().charAt(0);
        while (f != 'O'){
            if (f == 'F'){
                r = (mid - 1);
            }
            else{
                l = mid  + 1;
            }
            mid = (l + r) / 2;
            System.out.println(mid); System.out.flush();
            f = in.nextLine().charAt(0);
        }
        System.exit(0);
    }
}