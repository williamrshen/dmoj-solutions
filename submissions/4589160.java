import java.util.*;
public class PrettyAveragePrimes {
    public static boolean primeChecker(int input){
        boolean prime = true;
        for (int i = 2; i * i <= input; i++){
            if (input % i == 0){
                prime = false;
                break;
            }
        }
        return prime;
    }
    public static void main(String[] args){
        Scanner cs = new Scanner(System.in);
        int loops = cs.nextInt();
        int input;
        int A;
        int B;
        int j;
        for (int i = 0; i < loops; i++){
            input = cs.nextInt();
            j = 2;
            while (true){
                A = j;
                B = 2*input-j;
                if (primeChecker(A) && primeChecker(B)){
                    break;
                }
                j++;
            }
            System.out.println(A + " " + B);
        }
    }
}