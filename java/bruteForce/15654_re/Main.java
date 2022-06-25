import java.io.*;
import java.util.*;

public class Main {

	static int n, m;
	static ArrayList<Integer> seq = new ArrayList<>();
	static ArrayList<Integer> ans = new ArrayList<>();
	static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
	static boolean[] vi = new boolean[10002];

	static void f() throws IOException {
		if (ans.size() == m) {
			for (Integer nn : ans) {
				w.write(nn + " ");
			}
			w.write("\n");
			return;
		}
		
		for (int i = 0; i < n; i++) {
			int e = seq.get(i);
			if (vi[e]) continue;
			ans.add(e);
			vi[e] = true;
			f();
			vi[e] = false;
			ans.remove(ans.size() - 1);
		}
	}


	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(r.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(r.readLine());
		for (int i = 0; i < n; i++) {
			int tmp = Integer.parseInt(st.nextToken());
			seq.add(tmp);
		}
		Collections.sort(seq);
		f();
		w.flush();
	}
}
