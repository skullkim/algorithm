import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
		Integer[] li = new Integer[3];

		for (int i = 0; i < 3; i++) li[i] = Integer.parseInt(st.nextToken());

		int sum = li[0] + li[1] + li[2];
		if (sum % 3 != 0) {
			bw.write("0");
			bw.flush();
			return;
		}

		boolean[][] vi = new boolean[1501][1501];

		int[] idx1 = {0, 0, 1};
		int[] idx2 = {1, 2, 2};
		int[] idx3 = {2, 1, 0};

		Queue<Integer[]> q = new LinkedList<>();
		Arrays.sort(li);
		q.add(li);
		vi[li[0]][li[1]] = true;
		boolean hasAns = false;
		while (!q.isEmpty()) {
			Integer[] curr = q.peek();	
			q.poll();	

			if (curr[0] == curr[1] && curr[1] == curr[2]) {
				bw.write("1");
				bw.flush();
				hasAns = true;
				break;
			}
		
			for (int i = 0; i < 3; i++) {
				int i1 = idx1[i], i2 = idx2[i];
				int n1 = curr[i1], n2 = curr[i2];
				
				if(n1 == n2) continue;
				
				int tn1 = 0, tn2 = 0;
				if (n1 < n2) {
					tn1 = n1 + n1; tn2 = n2 - n1;
				} else {
					tn2 = n2 + n2; tn1 = n1 - n2;
				}
				
				Integer[] tmp = {tn1, tn2, sum - tn1 - tn2};
				Arrays.sort(tmp);
			
				if (vi[tmp[0]][tmp[1]]) continue;
				vi[tmp[0]][tmp[1]] = true;
				q.add(tmp);
			}
		}

		if (!hasAns) {
			bw.write("0");
			bw.flush();
		}
  }
}
