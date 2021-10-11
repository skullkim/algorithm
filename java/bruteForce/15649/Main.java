import java.io.*;
import java.util.*;

public class Main {
	static final int MAX = 10;
	static int n, m;
	static boolean vi[];
	ArrayList<Integer> ans = new ArrayList<Integer>();

	static public void func(int prev, int cnt) {
		if(cnt == m) {
			for(Integer i : ans) {
				System.out.print(i +  " ");
			}	
			System.out.println();
			return;
		}

		for(int i = 1; i <= n; i++) {
			if(i == prev || vi[i]) continue;
			vi[i] = true;
			ans.add(i);
			func(i, cnt + 1);
			ans.remove(ans.size() - 1);
			vi[i] = false;
		}
	}

	static public void main(String[] args) throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tz = new StringTokenizer(reader.readLine());
		n = Integer.parseInt(tz.nextToken());
		m = Integer.parseInt(tz.nextToken());
		vi = new boolean[MAX];
		func(0, 0);
	}
}
