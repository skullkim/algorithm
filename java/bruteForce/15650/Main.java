import java.io.*;
import java.util.*;

public class Main {
	static int n, m;
	static ArrayList<Integer> al = new ArrayList<Integer>();

	public static void f(int num, int cnt) {
		if(cnt == m) {
			for(Integer i : al) {
				System.out.print(i + " ");
			}
			System.out.println();
			return;
		}

		for(int i = num; i <= n; i++) {
			al.add(i);
			f(i + 1, cnt + 1);
			al.remove(al.size() - 1);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		f(1, 0);
	}
}
