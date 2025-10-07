import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int row, col;
	static char[][] g = new char[50][50];
	static class Pos {
		int y; int x;
		public Pos(int y, int x) {
			this.y = y; this.x = x;
		}
	}
	static Pos[] DIR = {new Pos(-1, 0), new Pos(1, 0), new Pos(0, -1), new Pos(0, 1)};
	static byte[][] vi = new byte[50][50];
	static boolean hasAns = false;

	public static void dfs(int y, int x, int dp, Pos start, char target) {
		vi[y][x] = 1;

		for (int i = 0; i < 4; i++) {
			int ny = y + DIR[i].y, nx = x + DIR[i].x;
			if (0 > ny || ny >= row || 0 > nx || nx >= col) continue;
			
			if (dp >= 4 && ny == start.y && nx == start.x) {
				hasAns = true;
				return;
			}
			if (vi[ny][nx] == 1 || g[ny][nx] != target) continue;
			dfs(ny, nx, dp + 1, start, target);
			
			if (hasAns) return;
		}

	}

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
		row = Integer.parseInt(st.nextToken());
		col = Integer.parseInt(st.nextToken());
		for (int i = 0; i < row; i++) {
			char[] arr = (new StringTokenizer(br.readLine())).nextToken().toCharArray();
			for (int k = 0; k < col; k++) {
				g[i][k] = arr[k];
			}
		}
		
		for (int i = 0; i < row; i++) {
			for (int k = 0; k < col; k++) {
				for (int r = 0; r < 50; r++) {
					Arrays.fill(vi[r], (byte)0);	
				}

				dfs(i, k, 1, new Pos(i, k), g[i][k]);
				if (hasAns) {
					bw.write("Yes");
					bw.flush();
					return;
				}
			}
		}

		bw.write("No");
		bw.flush();
  }
}
