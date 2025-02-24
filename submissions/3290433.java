import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


//  2014 s2/j5
        int n = sc.nextInt();
        LinkedList<String> firstList = new LinkedList<String>();
        LinkedList<String> secondList = new LinkedList<String>();
        for (int f = 0; f < n; f++) {
            firstList.add(sc.next());
        }
        for (int f = 0; f < n; f++) {
            secondList.add(sc.next());
        }

        for (int i = 0; i < n; i++) {
            String person = firstList.get(i);
            String partner = secondList.get(i);

            if (person.equals(partner)) {
                System.out.println("bad");
                return;
            }

            int partnerIndex = firstList.indexOf(partner);
            String person2 = secondList.get(partnerIndex);

            if (!person2.equals(person)) {
                System.out.println("bad");
                return;
            }

        }
        System.out.println("good");
        return;

    }
}