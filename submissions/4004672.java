import java.util.*;
import java.io.*;
public class ccc03s1 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		int newspace = 1;
		int oldspace;
		while(newspace<100){
			int moves = readInt();
			oldspace = newspace;
			newspace += moves;
			if (moves == 0) {
			    System.out.println("You Quit!");
			    break;
			}
			if(newspace == 100){
				System.out.println("You are now on square 100");
				System.out.println("You Win!");
				break;
			}
			else if(newspace>100){
				newspace = oldspace;
				System.out.println("You are now on square " + newspace);
			
			}
			else if(newspace==54){
				newspace = 19;
				System.out.println("You are now on square "+ newspace);
			}
			else if(newspace==90){
				newspace = 48;
				System.out.println("You are now on square "+ newspace);
			}
			else if(newspace==99){
				newspace = 77;
				System.out.println("You are now on square "+ newspace);
			}
			else if(newspace==9){
				newspace = 34;
				System.out.println("You are now on square "+ newspace);
			}
			else if(newspace==40){
				newspace = 64;
				System.out.println("You are now on square "+ newspace);
			}
			else if(newspace==67){
				newspace = 86;
				System.out.println("You are now on square "+ newspace);
			}
			else{
				System.out.println("You are now on square "+ newspace);
			}
		}
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