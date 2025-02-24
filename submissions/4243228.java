import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Administrator
 */
public class mimiAndDivision {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static int n;
    public static int s;
    public static int[] a;
    public static int[][] block;
    
    public static void main(String[] args) throws IOException {
        n = readInt();
        int q = readInt();
        s = (int)Math.ceil(Math.sqrt(n));
        a = new int[n];
        block = new int[s][200001];
        for(int index = 0; index < n; index++) {
            int k = readInt();
            int lasti = 1;
            a[index] = k;
            int blockIndex = index/s;
            for(int i = 1; i*i <= k; i++) {
                if(k%i==0) {
                    block[blockIndex][i]++;
                    block[blockIndex][k/i]++;
                    lasti = i;
                }
            }
            if(lasti*lasti==k) block[blockIndex][lasti]--;
        }
        for(int i = 0; i < q; i++) {
            int qType = readInt();
            if(qType == 1) {
                int l = readInt()-1; int r = readInt()-1; int x = readInt();
                int lBlock = l/s; int rBlock = r/s;
                long ans = 0;
                if(lBlock == rBlock) {
                    for(int j = l; j <= r; j++) {
                        if(a[j]%x == 0) ans++;
                    }
                }
                else {
                    for(int j = l; j < s*(lBlock+1); j++) {
                        if(a[j]%x == 0) ans++;
                    }
                    for(int j = lBlock+1; j < rBlock; j++) {
                        ans += block[j][x];
                    }
                    for(int j = s*rBlock; j <= r; j++) {
                        if(a[j]%x == 0) ans++;
                    }
                }
                System.out.println(ans);
            }
            else {
                int index = readInt()-1;
                int change = readInt();
                change(index, change);
            }
        }
    }
    
    public static void change(int index, int change) {
        int blockIndex = index/s;
        int lasti = 1;
        int prev = a[index];
        for(int i = 1; i*i <= prev; i++) {
            if(prev%i==0) {
                block[blockIndex][i]--;
                if(prev/i!=i)block[blockIndex][prev/i]--;
            }
        }
        if(lasti*lasti == prev) block[blockIndex][lasti]--;
        lasti = 1;
        a[index] = change;
        for(int i = 1; i*i <= change; i++) {
            if(change%i==0) {
                block[blockIndex][i]++;
                block[blockIndex][change/i]++;
                lasti = i;
            }
        }
        if(lasti*lasti == change) block[blockIndex][lasti]--;
    }
    
    static String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(br.readLine().trim());
            return st.nextToken();
    }

    static int readInt() throws IOException {
            return Integer.parseInt(next());
    }
}