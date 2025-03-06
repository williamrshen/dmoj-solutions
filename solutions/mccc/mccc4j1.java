import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    String costs = input.nextLine();
    String tickets = input.nextLine();
    String[] temp1 = costs.split(" ");
    String[] temp2 = tickets.split(" ");

    int F = Integer.parseInt(temp1[0]);
    int M = Integer.parseInt(temp1[1]);
    int B = Integer.parseInt(temp1[2]);

    int tF = Integer.parseInt(temp2[0]);
    int tM = Integer.parseInt(temp2[1]);
    int tB = Integer.parseInt(temp2[2]);

    System.out.println((tF + tM + tB) + " " + (F * tF + M * tM + B * tB));
  }
}