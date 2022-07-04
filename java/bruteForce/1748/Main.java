import java.util.*;
import java.io.*;

public class Main {

	static int n, digits = 1, totalPerDigits = 9;
	static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		StringTokenizer st = new StringTokenizer(r.readLine());
		n = Integer.parseInt(st.nextToken());
		int ans = 0;
		while (n >= totalPerDigits) {
			ans += totalPerDigits * digits;
			n -= totalPerDigits;
			totalPerDigits *= 10;
			digits++;
		}
		ans += n * digits;
		w.write(ans + "\n");
		w.flush();
	}
}
