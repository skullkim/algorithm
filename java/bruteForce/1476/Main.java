import java.util.*;
import java.io.*;

public class Main {

	static int te, ts, tm;
	static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {

		StringTokenizer st = new StringTokenizer(r.readLine());
		te = Integer.parseInt(st.nextToken());
		ts = Integer.parseInt(st.nextToken());
		tm = Integer.parseInt(st.nextToken());

		int e = 1, s = 1, m = 1, ans = 1;;

		while (true) {
			if (e == 16) e = 1;
			if (s == 29) s = 1;
			if (m == 20) m = 1;
			if (e == te && s == ts && m == tm) break;
			e++; s++; m++;
			ans++;
		}
		w.write(ans + "\n");
		w.flush();
	}
}
