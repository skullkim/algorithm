import java.io.*;
import java.util.*;

public class Main {
	static final int MAX = 987654321;
	static ArrayList<Integer> al = new ArrayList<>();
	static ArrayList<Integer> ans = new ArrayList<>();
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static boolean[] vi = new boolean[MAX];
	static int n, m;

	public static void f(int cnt) throws IOException {
		if(cnt >= m) {
			for(int i =0; i < ans.size(); i++) {
				bw.write(ans.get(i) + " ");
			}
			bw.write("\n");
			return;
		}

		for(int i = 1; i <= n; i++) {
			if(vi[i]) continue;
			ans.add(al.get(i));
			vi[i] = true;
			f(cnt + 1);
			vi[i] = false;
			ans.remove(ans.size() - 1);
		}
	}

	public static void main(String[] args) throws IOException{
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		al.add(-1);
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			al.add(Integer.parseInt(st.nextToken()));
		}
		Collections.sort(al);
		f(0);
		bw.flush();
	}
}
