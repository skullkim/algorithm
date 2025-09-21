import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n, k;
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		List<Integer> strong = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < 2 * n; i++) {
			strong.add(Integer.parseInt(st.nextToken()));
		}

		List<Integer> rbs = new ArrayList<>();
		int ans = 0;
		while (true) {
			for (int i = 0; i < rbs.size(); i++) {
				int currP = rbs.get(i);
				int ntP = 0;
				if (currP == 2*n-1) ntP = 0;
				else ntP = currP + 1;

				rbs.set(i, ntP);
			}

			for (int i = 0; i < rbs.size(); i++) {
				int currP = rbs.get(i);
				int ntP = 0;
				if (currP == 2*n-1) ntP = 1;
				else ntP = currP + 1;
				
				int str = strong.get(i);
				if (str > 0) {
					rbs.set(i, ntP);
					strong.set(i, str - 1);
					if (strong.get(i) == 0) ans++;
				}
				
				if (rbs.get(i) == n - 1) {
					rbs.remove(i);
					i--;
				}
			}
			
			if (strong.get(0) != 0) {
				rbs.add(0);
				int str = strong.get(0);
				strong.set(0, str - 1);
				if (strong.get(0) == 0) ans++;
			}

			for (int i = 0; i < strong.size(); i++) {
				System.out.print(strong.get(i) + " ");
			}
			System.out.println();

			if (ans >= k) break;
		}

		bw.write(ans + "");
		bw.flush();
  }
}
