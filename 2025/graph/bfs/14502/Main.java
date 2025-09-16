import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int rows, cols;
	static int[][] g = new int[8][8];
	static int W = 1, V = 2, E = 0;

	static class Pos {
		int y; int x;
		Pos(int y, int x) {
			this.y = y; this.x = x;
		}
	}
	static Pos[] DIR = {new Pos(-1, 0), new Pos(1, 0), new Pos(0, -1), new Pos(0, 1)};
	static List<Pos> es = new ArrayList<>();
	static List<Pos> vis = new ArrayList<>();
	static int ans = 0, sf = 0;

	static void bfs(List<Pos> ep) {
		int[][] cg = new int[rows][cols];
		for (int i = 0; i < rows; i++) {
			for (int k = 0; k < cols; k++) {
				cg[i][k] = g[i][k];
			}
		}
		for (int i = 0; i < ep.size(); i++) {
			Pos tmp = ep.get(i);
			cg[tmp.y][tmp.x] = W;
		}	

		boolean[][] vi = new boolean[rows][cols];
		for (int i = 0; i < rows; i++) {
			Arrays.fill(vi[i], false);
		}

		Queue<Pos> q = new LinkedList<>();
		for (int i = 0; i < vis.size(); i++) {
			q.add(vis.get(i));
		}
		while (!q.isEmpty()) {
			Pos curr = q.peek();
			vi[curr.y][curr.x] = true;
			cg[curr.y][curr.x] = V;
			q.poll();
			
			for (int i = 0; i < 4; i++) {
				Pos nt = new Pos(curr.y + DIR[i].y, curr.x + DIR[i].x);
				if (0 > nt.y || nt.y >= rows || 0 > nt.x || nt.x >= cols) continue;
				if (vi[nt.y][nt.x] || cg[nt.y][nt.x] != E) continue;
				vi[curr.y][curr.x] = true;
				q.add(nt);
			}
		}

//		if (ep.get(0).y == 0 && ep.get(0).x == 1 
//				&& ep.get(1).y == 1 && ep.get(1).x == 0 
//				&& ep.get(2).y == 3 && ep.get(2).x == 5) {
//
//			System.out.println(csf);
//			for (int i = 0; i < rows; i++) {
//				for (int k = 0; k < cols; k++) {
//					System.out.print(cg[i][k] + " ");
//				}
//				System.out.println();
//			}
//				System.out.println();
//		}
		int tmp = 0;
		for (int i = 0; i < rows; i++) {
			for (int k = 0; k < cols; k++) {
				if (cg[i][k] == E) tmp++;
			}
		}
		ans = Math.max(ans, tmp);
	}

	static void f(List<Pos> curr, int idx) {
		if (curr.size() == 3) {
			if (curr.get(0).y == 0 && curr.get(0).x == 1) {
//				for (int i = 0; i < 3; i++) {
//					Pos p = curr.get(i);
//					System.out.print(p.y + " " + p.x + ", ");
//				}
//				System.out.println();
			}
			bfs(curr);
			return;
		}

		for (int i = idx; i < es.size(); i++) {
			curr.add(es.get(i));
			f(curr, i + 1);
			curr.remove(curr.size() - 1);
		}
	}

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
		rows = Integer.parseInt(st.nextToken());
		cols = Integer.parseInt(st.nextToken());
		
		for (int i = 0; i < rows; i++) {
			st = new StringTokenizer(br.readLine());
			for (int k = 0; k < cols; k++) {
				g[i][k] = Integer.parseInt(st.nextToken());
				if (g[i][k] == E) {
					Pos tmp = new Pos(i, k);
					es.add(tmp);
					sf++;
				} else if (g[i][k] == V) vis.add(new Pos(i, k));
			}
		}

		f(new ArrayList<Pos>(), 0);

		bw.write(ans + "");
		bw.flush();
  }
}
