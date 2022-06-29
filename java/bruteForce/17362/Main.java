import java.io.*;
import java.util.*;

public class Main {

	static int n, m = 1;
	static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main (String[] args) throws IOException {
		StringTokenizer st = new StringTokenizer(r.readLine());
		n = Integer.parseInt(st.nextToken());
		boolean op = true;
		for (int i = 1; i < n; i++) {
			if (m == 1) op = true;
			else if (m == 5) op = false; 
			if (op) m++;
			else m--;
		}
		w.write(m + "\n");
		w.flush();
	}

}
