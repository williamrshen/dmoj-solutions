import java.io.IOException;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        for (int q = 0; q < 5; q ++) {

            char[] l = sc.nextLine().toCharArray();
            StringBuilder sb = new StringBuilder();
            for (int k = 0; k < l.length; k ++) {
                if (l[k] == '/') {

                    if (l[k + 1] == '/') {
                        for (int i = k + 2; i < l.length; i ++) {
                            sb.append(l[i]);
                        }
                        break;
                    } else if (l[k + 1] == '*') {
                        for (int i = k + 2; i < l.length; i ++) {
                            if (l[i] == '*' && l[i + 1] == '/') {
                                k = i + 2;
                                sb.append(" ");
                                break;
                            }
                            sb.append(l[i]);
                        }
                    }

                } else if (l[k] == '\'') {
                    for (int i = k + 1; i < l.length; i ++) {
                        if (l[i] == '\'') {
                            k = i + 1;
                            sb.append(" ");
                            break;
                        }
                        sb.append(l[i]);
                    }
                } else if(l[k] == '"') {
                    for (int i = k + 1; i < l.length; i ++) {
                        if (l[i] == '"') {
                            k = i + 1;
                            sb.append(" ");
                            break;
                        }
                        sb.append(l[i]);
                    }
                }
            }
            System.out.println(sb.toString().trim());
        }
    }
}