import java.io.*;
import java.util.*;

public class Main {

	static int n, m;
	static ArrayList<Integer> seq = new ArrayList<>();
	static ArrayList<Integer> ans = new ArrayList<>();
	static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
	static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

	static void f() throws IOException {
		if (ans.size() == m) {
			for (Integer nn : ans) {
				w.write(nn + " ");
			}
			w.write("\n");
			return;
		}

		for (int i = 0; i < n; i++) {
			ans.add(seq.get(i));
			f();
			ans.remove(ans.size() - 1);
		}
	}

	public static void main(String[] args) throws IOException {
		StringTokenizer st = new StringTokenizer(r.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(r.readLine());
		for (int i = 0; i < n; i++) {
			seq.add(Integer.parseInt(st.nextToken()));
		}
		Collections.sort(seq);
		f();
		w.flush();
	}
}
