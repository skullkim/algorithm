import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	static int r, c, rots;
	static int[][] arr = new int[300][300];
	static class Pos {
		int y; int x;
		public Pos(int y, int x) {
			this.y = y; this.x = x;
		}
	}
	static Pos[] DIR = {new Pos(1, 0), new Pos(0, 1), new Pos(-1, 0), new Pos(-1, 0)};

	static void swap(Pos p1, Pos p2) {
		int tmp = arr[p1.y][p1.x];
		arr[p1.y][p1.x] = arr[p2.y][p2.x];
		arr[p2.y][p2.x] = tmp;
	}

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		rots = Integer.parseInt(st.nextToken());

		for (int i = 0; i < r; i++) {
			st = new StringTokenizer(br.readLine());
			for (int k = 0; k < c; k++) {
				arr[i][k] = Integer.parseInt(st.nextToken());
			}
		}
	
		while(true) {
			if (rots <= 0) break;
			Pos stp = null, curr = null, nt = null;
			int rlen = r, clen = c;
			int rr = Math.min(r, c) / 2;
			while(true) {
				rr--;
				if (rr < 0) break;
				if (stp == null) {
					stp = new Pos(0, 0);
				} else {
					stp.y++; stp.x++;
				}
				
				curr = new Pos(stp.y, stp.x);
				for (int i = 1; i < rlen; i++) {
					nt = new Pos(curr.y + 1 * i, curr.x);
					swap(stp, nt);
				}
				
				curr = new Pos(nt.y, nt.x);
				for (int i = 1; i < clen; i++) {
					nt = new Pos(curr.y, curr.x + 1 * i);
					swap(stp, nt);
				}

				curr = new Pos(nt.y, nt.x);
				for (int i = 1; i < rlen; i++) {
					nt = new Pos(curr.y - 1 * i, curr.x);
					swap(stp, nt);
				}

				curr = new Pos(nt.y, nt.x);
				for (int i = 1; i < clen; i++) {
					nt = new Pos(curr.y, curr.x - 1 * i);
					swap(stp, nt);
				}

				rlen -= 2; clen -= 2;
			}
			rots--;
		}

		
		
		for (int i = 0; i < r; i++) {
			for (int k = 0; k < c; k++) {
				bw.write(arr[i][k] + " ");
			}
			bw.write("\n");
		}

		bw.flush();
  }
}
