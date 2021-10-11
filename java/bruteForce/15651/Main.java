import java.io.*;
import java.util.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> al = new ArrayList<>();

	public static void f(int cnt) throws IOException {
		if(cnt == m) {
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			for(int i : al) {
				bw.write(i + " ");
				bw.flush();
			}
			bw.write("\n");
			bw.flush();
			return;
		}

		for(int i = 1; i <= n; i++) {
			al.add(i);
			f(cnt + 1);
			al.remove(al.size() - 1);
		}
	}


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tz = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tz.nextToken());
		m = Integer.parseInt(tz.nextToken());
		f(0);
	}
}

