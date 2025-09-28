import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	static int ROT = 1, R_ROT = -1, NO_ROT = 0, N = 0, S = 1;

	static class Info {
		int l, r, t;
		public Info(int l, int r, int t) {
			this.l = l; this.r = r; this.t = t;
		}

		void rot(int dir) {
			if (dir == NO_ROT) return;
			if (dir == R_ROT) {
				l++; r++; t++;
				if (l >= 8) l = 0;
				if (r >= 8) r = 0;
				if (t >= 8) t = 0;
			} else {
				l--; r--; t--;
				if (l < 0) l = 7;
				if (r < 0) r = 7;
				if (t < 0) t = 7;
			}
		}
	}
	static List<Info> list = new ArrayList<>();

	static int findDir(int currIdx, int ntIdx, int currDir, int[][] arr) {
		Info curr = list.get(currIdx);
		Info nt = list.get(ntIdx);

//		System.out.println(currIdx + ", " + curr.l + ", " + curr.r + ", " + curr.t);
//		System.out.println(ntIdx + ", " + nt.l + ", " + nt.r + ", " + nt.t);
//		System.out.println();

		int[] curr_arr = arr[currIdx];
		int[] nt_arr = arr[ntIdx];

		if (currIdx > ntIdx) {
			if (nt_arr[nt.r] != curr_arr[curr.l]) {
				if (currDir == ROT) return R_ROT;
				else return ROT;
			} else return NO_ROT;
		} else {
			if (nt_arr[nt.l] != curr_arr[curr.r]) {
				if (currDir == ROT) return R_ROT;
				else return ROT;
			} else return NO_ROT;
		}
	}
	
  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
		int ts = Integer.parseInt(st.nextToken());
		
		int[][] arr = new int[ts][8];
		for (int i = 0; i < ts; i++) {
			st = new StringTokenizer(br.readLine());
			char[] tmp = st.nextToken().toCharArray();
			for (int k = 0; k < 8; k++) {
				arr[i][k] = tmp[k] - '0';
			}

			list.add(new Info(6, 2, 0));
		}

		int rots, target, dir;
		st = new StringTokenizer(br.readLine());
		rots = Integer.parseInt(st.nextToken());

		while (rots > 0) {
			st = new StringTokenizer(br.readLine());
			target = Integer.parseInt(st.nextToken()) - 1;
			dir = Integer.parseInt(st.nextToken());

//		for (int i = 0; i < ts; i++) {
//			Info a = list.get(i);
//			System.out.println(a.l + ", " + a.r + ", " + a.t);
//		}
//System.out.println();


			int[] tmp = new int[ts];
			tmp[target] = dir;
			int currDir = dir;

			for (int i = target; i < ts - 1; i++) {
				int d = findDir(i, i + 1, currDir, arr);
				currDir = d;
				if (d == NO_ROT) {
					for (int k = i + 1; k < ts; k++) tmp[k] = NO_ROT;
					break;
				} else tmp[i + 1] = d;
			}

			currDir = dir;
			for (int i = target; i >= 1; i--) {
				int d = findDir(i, i - 1, currDir, arr);
				currDir = d;
				if (d == NO_ROT) {
					for (int k = i - 1; k >= 0; k--) {
						tmp[k] = NO_ROT;
					}
					break;
				} else tmp[i - 1] = d;
			}

//		for (int i = 0; i < ts; i++) System.out.print(tmp[i] + " ");
//		System.out.println();
//		System.out.println();
			
			for (int i = 0; i < ts; i++) {
				list.get(i).rot(tmp[i]);
			}
			rots--;
		}


		int ans = 0;
		for (int i = 0; i < ts; i++) {
			Info a = list.get(i);
			if (arr[i][list.get(i).t] == S) ans++;
		}

		bw.write(ans + "");
		bw.flush();
  }
}
