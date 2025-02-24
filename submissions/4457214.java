import java.util.*;
import java.io.*;
public class Main{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static Set<String> ughdupes = new HashSet();
	public static void ughuselessleafaddingtomyworkload(StringBuilder ans, String ssssssstuckup, String tyrannosaurusrex){
	    if(ssssssstuckup.isEmpty() && tyrannosaurusrex.isEmpty()){
	        ughdupes.add(ans.toString());
	        return;
	    }
	    
	    if(!ssssssstuckup.isEmpty()) {
	        ughuselessleafaddingtomyworkload(ans.append(ssssssstuckup.charAt(0)), ssssssstuckup.substring(1), tyrannosaurusrex);
	        ans.delete(ans.length() - 1, ans.length());
	    }
	    
	    if(!tyrannosaurusrex.isEmpty()) {
	        ughuselessleafaddingtomyworkload(ans.append(tyrannosaurusrex.charAt(0)), ssssssstuckup, tyrannosaurusrex.substring(1));
	        ans.delete(ans.length() - 1, ans.length());
	    }
	}
	public static void main(String[] args) throws IOException{
		String ssssssstuckup = next(), tyrannosaurusrex = next();
		StringBuilder x = new StringBuilder();
		ughuselessleafaddingtomyworkload(x, ssssssstuckup, tyrannosaurusrex);
		for(String tsk : ughdupes) System.out.println(tsk);
	}
	static String next() throws IOException{
		while(st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static int readInt() throws IOException{
		return Integer.parseInt(next());
	}
	static long readLong() throws IOException{
		return Long.parseLong(next());
	}
	static String readLine() throws IOException{
		return br.readLine();
	}
}