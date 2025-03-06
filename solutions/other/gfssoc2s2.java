import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        Card[] c = new Card[n];
        for (int i = 0; i < n; i ++) {
            c[i] = new Card(sc.next(), sc.nextInt());
        }
        Arrays.sort(c);
        for (int i = 0; i < n - 2; i ++) {
            for (int j = i + 1; j < n - 1; j ++) {
                for (int k = j + 1; k < n; k ++) {
                    if (c[i].cost + c[j].cost + c[k].cost <= t) {
                        System.out.println(c[i].name + " " + c[j].name + " " + c[k].name);
                    }
                }
            }
        }
    }

    public static class Card implements Comparable<Card>{
        String name;
        int cost;
        public Card (String n, int cos) {
            this.name = n;
            this.cost = cos;
        }
        public int compareTo (Card o) {
            return this.name.compareTo(o.name);
        }
    }
}