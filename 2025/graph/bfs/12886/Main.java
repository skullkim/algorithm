import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
		List<Integer> li = new ArrayList<>();

		for (int i = 0; i < 3; i++) li.add(Integer.parseInt(st.nextToken()));

		boolean[][][] vi = new boolean[1001][1001][1001];
		for (int i = 0; i < 501; i++) {
			for (int k = 0; k < 501; k++) Arrays.fill(vi[i][k], false);
		}

		int[] idx1 = {0, 0, 1};
		int[] idx2 = {1, 2, 2};
		int[] idx3 = {2, 1, 0};

		Queue<List<Integer>> q = new LinkedList<>();
		q.add(li);
		boolean hasAns = false;
		while (!q.isEmpty()) {
			List<Integer> curr = q.peek();	
			q.poll();	

			if (curr.get(0) == curr.get(1) && curr.get(1) == curr.get(2)) {
				bw.write("1");
				bw.flush();
				hasAns = true;
				break;
			}
			Collections.sort(curr);
			vi[curr.get(0)][curr.get(1)][curr.get(2)] = true;
		
			for (int i = 0; i < 3; i++) {
				int i1 = idx1[i], i2 = idx2[i];
				int n1 = curr.get(i1), n2 = curr.get(i2);

				if (n1 < n2) {
					n1 = n1 + n1; n2 = n2 - n1;
				} else {
					n2 = n2 + n2; n1 = n1 - n2;
				}
				if (n1 <= 0 || n2 <= 0) continue;
				List<Integer> tmp = new ArrayList<>();
				tmp.add(n1); tmp.add(n2); tmp.add(curr.get(idx3[i]));
				Collections.sort(tmp);
			
				if (vi[tmp.get(0)][tmp.get(1)][tmp.get(2)]) continue;
				q.add(tmp);
			}
		}

		if (!hasAns) {
			bw.write("0");
			bw.flush();
		}
  }
}
