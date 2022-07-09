import java.util.*;
import java.io.*;

public class Main {

	static int cases, n, sum = 0, ans = 0;
	static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void f() {
		if (sum > n) return;
		if (sum == n) {
			ans++;
			return;
		}

		for (int i = 1; i <= 3; i++) {
			sum += i;
			f();
			sum -= i;
		}
	}

	public static void main(String[] args) throws IOException {
		StringTokenizer st = new StringTokenizer(r.readLine());
		cases = Integer.parseInt(st.nextToken());
		while(cases-- > 0) {
			st = new StringTokenizer(r.readLine());
			n = Integer.parseInt(st.nextToken());
			f();
			w.write(ans + "\n");
			w.flush();
			ans = 0;
			sum = 0;
		}
	}
}
