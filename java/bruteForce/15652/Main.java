import java.io.*;
import java.util.*;

public class Main {
	static ArrayList<Integer> al = new ArrayList<>();
	static int n, m;
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void f(int cnt, int num) throws IOException {
		if(cnt == m) {
			for(int i =0 ; i < al.size(); i++) {
				bw.write(al.get(i) + " ");
			}
			bw.write("\n");
			return;
		}

		for(int i = num; i <= n; i++) {
			al.add(i);
			f(cnt + 1, i);
			al.remove(al.size() - 1);
		}
	}

	public static void main(String[] args) throws IOException {
		StringTokenizer tz = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tz.nextToken());
		m = Integer.parseInt(tz.nextToken());
		f(0, 1);
		bw.flush();
	}
}
