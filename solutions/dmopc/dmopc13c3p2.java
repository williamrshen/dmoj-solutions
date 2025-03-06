import java.util.*;
import java.io.*;
import java.math.*;
import java.text.*;

public class Main {


    public static int[] parent;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);


        Calendar cal = Calendar.getInstance();

        int set = sc.nextInt();
        sc.nextLine();
        String dateTime = sc.nextLine();

        DateFormat formatter = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
        Date currentDate = formatter.parse(dateTime);

        cal.setTime(currentDate);
        cal.add(Calendar.HOUR, -set);
        Date back = cal.getTime();
        System.out.println(formatter.format(back));
        
        
        






    }

}