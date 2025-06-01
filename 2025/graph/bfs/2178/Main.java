import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static class Pos {
    int y; int x;
    Pos(int y, int x) {
      this.y = y; this.x = x;
    }
  }
  static Pos[] dir = {new Pos(-1, 0), new Pos(1, 0), new Pos(0, -1), new Pos(0, 1)};
  static boolean[][] vi = new boolean[102][102];
  static int[][] ans = new int[102][102];
  static int[][] g = new int[102][102];
  static int h, w;

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    h = Integer.parseInt(st.nextToken());
    w = Integer.parseInt(st.nextToken());
    for (int i = 0; i < h; i++) {
      char[] r = br.readLine().toCharArray();
      for (int k = 0; k < r.length; k++) {
        g[i][k] = r[k] - '0';
      }
    }

    ans[0][0] = 1;
    Queue<Pos> q = new LinkedList<>();
    q.offer(new Pos(0, 0));
    while (!q.isEmpty()) {
      Pos curr = q.peek();
      q.poll();
      if (vi[curr.y][curr.x]) continue;
      vi[curr.y][curr.x] = true;

      for (int i = 0; i < 4; i++) {
        Pos nt = new Pos(curr.y + dir[i].y, curr.x + dir[i].x);
        if (0 > nt.y || nt.y >= h || 0 > nt.x || nt.x >= w) continue;
        if (g[nt.y][nt.x] == 0 || vi[nt.y][nt.x]) continue;
        q.offer(nt);
        ans[nt.y][nt.x] = ans[curr.y][curr.x] + 1;
      }
    }

    bw.write(ans[h - 1][w - 1] + "");
    bw.flush();
  }
}
