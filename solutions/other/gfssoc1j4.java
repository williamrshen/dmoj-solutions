import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
//        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean OWin = false;
        boolean XWin = false;

        String row1 = br.readLine();
        String [] oneRow = row1.split("");
        String row2 = br.readLine();
        String [] twoRow = row2.split("");
        String row3 = br.readLine();
        String [] threeRow = row3.split("");

        String [] [] map = {oneRow, twoRow, threeRow};


        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (map[i][j].equals("X")) {
                    break;
                } else if (j == 2){
                    OWin = true;
                }

            }
        }
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (map[j][i].equals("X")) {
                    break;
                } else if (j == 2){
                    OWin = true;
                }

            }
        }
        for (int i = 0; i < 3; i ++) {
            if (map[i][i].equals("X")) {
                break;
            } else if (i == 2) {
                OWin = true;
            }

        }
        for (int i = 0; i < 3; i ++) {
            if (map[i][i * -1 + 2].equals("X")) {
                break;
            } else if (i == 2) {
                OWin = true;
            }
        }



        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (map[i][j].equals("O")) {
                    break;
                } else if (j == 2){
                    XWin = true;
                }

            }
        }
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (map[j][i].equals("O")) {
                    break;
                } else if (j == 2){
                    XWin = true;
                }
            }
        }
        for (int i = 0; i < 3; i ++) {
            if (map[i][i].equals("O")) {
                break;
            } else if (i == 2) {
                XWin = true;
            }



        }
        for (int i = 0; i < 3; i ++) {
            if (map[i][i * -1 + 2].equals("O")) {
                break;
            } else if (i == 2) {
                XWin = true;
            }
        }



        if (OWin == true) {
            if (XWin == true) {
                System.out.println("Error, redo");
            } else {
                System.out.println("Griffy");
            }
        } else {
            if (XWin == true) {
                System.out.println("Timothy");
            } else {
                System.out.println("Tie");
            }
        }

    }
}