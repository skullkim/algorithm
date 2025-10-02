import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
		Integer[] li = new Integer[3];

		for (int i = 0; i < 3; i++) li[i] = Integer.parseInt(st.nextToken());

		if ((li[0] + li[1] + li[2]) % 3 != 0) {
			bw.write("0");
			bw.flush();
			return;
		}

		Map<String, Boolean> vi = new HashMap<>();	

		int[] idx1 = {0, 0, 1};
		int[] idx2 = {1, 2, 2};
		int[] idx3 = {2, 1, 0};

		Queue<Integer[]> q = new LinkedList<>();
		Arrays.sort(li);
		q.add(li);
		vi.put((li[0] + "," + li[1] + "," + li[2]), true);
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
				n1 = tn1; n2 = tn2;
				if (n1 <= 0 || n2 <= 0) continue;
				Integer[] tmp = {n1, n2, curr[idx3[i]]};
				Arrays.sort(tmp);
			
				String key = tmp[0] + "," + tmp[1] + "," + tmp[2];
				if (vi.containsKey(key)) continue;
				vi.put(key, true);
				q.add(tmp);
			}
		}

		if (!hasAns) {
			bw.write("0");
			bw.flush();
		}
  }
}
