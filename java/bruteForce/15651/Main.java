import java.io.*;
import java.util.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> al = new ArrayList<>();
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void f(int cnt, int num) throws IOException {
		if(cnt == m) {
			for(int i = 0; i < al.size(); i++) {
				bw.write(al.get(i) + " ");
			}
			bw.write("\n");
			return;
		}
		
		for(int i = 1; i <= n; i++) {
			al.add(i);
			f(cnt + 1, i);
			al.remove(al.size() - 1);
		}
	}


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tz = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tz.nextToken());
		m = Integer.parseInt(tz.nextToken());
		f(0, 0);
		bw.flush();
	}
}

