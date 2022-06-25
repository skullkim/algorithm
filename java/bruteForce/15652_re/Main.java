import java.io.*;
import java.util.*;

public class Main {

	static int n, m;
	static ArrayList<Integer> arr = new ArrayList<>();
	static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

	static void f(int currN) throws IOException{
		if (m == arr.size()) {
			for (Integer nn : arr) {
				w.write(nn + " ");
			}
			w.write("\n");
			return;
		}


		for (int i = currN; i <= n; i++) {
			arr.add(i);
			f(i);
			arr.remove(arr.size() - 1);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(r.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		f(1);
		w.flush();
	}
}
