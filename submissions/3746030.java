import java.io.IOException;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        for (int q = 0; q < 5; q ++) {
            String line = sc.nextLine();
            String a = "";
            for (int i = 0; i < line.length(); i ++) {
                char cur = line.charAt(i);
                if (cur == '"') {
                    int next = line.indexOf("\"", i + 1);
                    a += " " + line.substring(i + 1, next);
                    i = next;
                } else if (cur == '\'') {
                    int next = line.indexOf("'", i + 1);
                    a += " " + line.substring(i + 1, next);
                    i = next;
                } else if (cur == '/') {
                    if (i + 1 >= line.length()) continue;
                    if(line.charAt(i+1) == '/'){
                        a += " " + line.substring(i+2);
                        break;
                    } else if(line.charAt(i+1) == '*'){
                        int next = line.indexOf("*/", i + 1);
                        a += " " + line.substring(i + 2, next);
                        i = next;
                    }

                }
            }
            System.out.println(a.trim());

        }
    }
}