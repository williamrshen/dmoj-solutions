import java.util.*;
public class IUFunction {
     public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int N = s.nextInt(), Q = s.nextInt();
        int[] arr = new int[N];
        for(int i =0; i<N; i++){
            arr[i] = s.nextInt();
        }
        Arrays.sort(arr);
        int[] result = new int[Q];
        for(int i =0; i<Q; i++){
            int L = s.nextInt();
            int R = s.nextInt();
            int index = Arrays.binarySearch(arr, L);
            int index2 = Arrays.binarySearch(arr, R);
            if(index<0){
                index = -index-1;
            }
            if(index2<0){
                index2 = -index2-2;
            }
            if(index2>=N && index>=N){
                result[i] = 0;
            } else{
                result[i] = index2 - index + 1;
            }
        }
        for(int i:result){
            System.out.println(i);
        }
        s.close();
    }
}