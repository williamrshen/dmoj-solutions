import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);

        //count how many letter in wrong position
        //count how many L
        //count how many M
        //count how many S

        String S = sc.next();
        int totalL = 0;
        int totalM = 0;
        int totalS = 0;
        //read char one by one and compare and increase the count
        for (int i=0; i<S.length(); i++) {
            if (S.charAt(i)=='L') {
                totalL++;
            } else if (S.charAt(i)=='M') {
                totalM++;
            } else {
                totalS++;
            }
        }

        //We want to know letter in wrong position
        //how many letter is M in L position   lm
        //how many letter is S in L position   ls
        int lm = 0;   //m in L position
        int ls = 0;   //s in L position
        for (int i=0; i<totalL; i++) {
            if (S.charAt(i)=='M') {
                lm++;
            } else if (S.charAt(i)=='S') {
                ls++;
            }
        }

        int ml = 0;   //l in M position
        int ms = 0;   //s in M position
        for (int i=totalL; i<totalL+totalM; i++) {
            if (S.charAt(i)=='L') {
                ml++;
            } else if (S.charAt(i)=='S') {
                ms++;
            }
        }

        int sl = 0;   //l in S position
        int sm = 0;   //m in S position
        for (int i=totalL+totalM; i<S.length(); i++) {
            if (S.charAt(i)=='L') {
                sl++;
            } else if (S.charAt(i)=='M') {
                sm++;
            }
        }


        //lm+ls+ml+ms+sl+sm  total letters in wrong position
        int two_1 = Math.min(ls,sl)+Math.min(lm, ml)+Math.min(sm, ms);
        System.out.println((lm+ls+ml+ms+sl+sm-2*two_1)/3*2+   //3 letter need 2 swap
                two_1);   //2 letter need 1 swap

    }
}