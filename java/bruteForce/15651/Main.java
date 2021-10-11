import java.io.*;
import java.util.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> al = new ArrayList<>();

	public static void f(int cnt) {
		if(cnt == m) {
			for(Integer i : al) {
				System.out.print(i + " ");
			}
			System.out.println();
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

