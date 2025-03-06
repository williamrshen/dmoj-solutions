import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

    int W = sc.nextInt();  //total Weight
    int N = sc.nextInt();   //input N as amount of car
    int[] car = new int[N];
    for(int i=0;i<N;i++){
      car[i] = sc.nextInt();
    }
    int sum = 0;
    for(int i=0;i<N;i++){
      if(i<4){
        sum=sum+car[i];
      }
      else{
        sum=sum+car[i]-car[i-4];
      }
      if(sum>W){
        System.out.println(i);
        return;
      }
      
    }
    System.out.println(N);
    

    }
}