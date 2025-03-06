import java.text.DecimalFormat;
import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        DecimalFormat format = new DecimalFormat();
        format.setDecimalSeparatorAlwaysShown(false);
        format.setGroupingUsed(false);
        int length = readInt();
        ArrayList<Integer> ray = new ArrayList<>();
        for (int i = 0; i < length; i++){
            ray.add(readInt());
        }
        ArrayList<Integer> ray2 = new ArrayList<>(ray);
        Collections.sort(ray2);
        ArrayList<Integer> ray3 = new ArrayList<>(ray2.subList(0,ray2.size()/2));
        System.out.print(ray2.get(0) + " ");
        System.out.print(ray2.get(ray2.size()-1) + " ");
        System.out.print(format.format(getMedian(ray3)) + " ");
        System.out.print(format.format(getMedian(ray2)) + " ");
        ArrayList<Integer> ray4 = new ArrayList<>(ray2.subList(ray2.size()/2,ray2.size()));
        if (ray2.size()%2 == 1){
        ray4 = new ArrayList<>(ray2.subList(ray2.size()/2 + 1, ray2.size()));
        }
        System.out.print(format.format(getMedian(ray4)));
        }
public static double getMedian(ArrayList<Integer> sets){
        Collections.sort(sets);

        double middle;
        if (sets.size()%2 == 0) {
        middle = (sets.get(sets.size()/2) + (double)sets.get(sets.size()/2 - 1))/2D;
        } else {
        middle = sets.get(sets.size() / 2);
        }
        return middle;
        }
static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
        st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
        }
static long readLong () throws IOException {
        return Long.parseLong(next());
        }
static int readInt () throws IOException {
        return Integer.parseInt(next());
        }
static double readDouble () throws IOException {
        return Double.parseDouble(next());
        }
static char readCharacter () throws IOException {
        return next().charAt(0);
        }
static String readLine () throws IOException {
        return br.readLine().trim();
        }
        }