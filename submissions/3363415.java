import java.util.*;
import java.io.*;    //1

public class Solution  
{
  public static void main (String args[]) throws Exception{
      //William
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        while (true) {
            int r = Integer.parseInt(br.readLine());
            if (r == 0) {
                break;
            }
            int sum = 0;
            for (int x = 0; x <= r; x ++) {
               int y = (int)(Math.sqrt(r*r-x*x));
               sum+=y;
            }
            System.out.println(4*sum+1);
        }


      
      }
    
}