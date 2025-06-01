import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static int w, h;

  static class Pos {
    int y; int x;
    Pos(int y, int x) {
      this.y = y; this.x = x;
    }
  }
  static Pos[] pos = {new Pos(-1, 0), new Pos(1, 0), new Pos(0, -1), new Pos(0, 1), new Pos(-1, 1), new Pos(1, 1), new Pos(1, -1), new Pos(-1, -1)};
  static boolean[][] vi = new boolean[55][55];

  public static void bfs(int[][] map, Pos st) {
    Queue<Pos> q = new LinkedList<>();
    q.offer(st);
    while (!q.isEmpty()) {
      Pos curr = q.peek();
      q.poll();
      if (vi[curr.y][curr.x]) continue;
      vi[curr.y][curr.x] = true;

      for (int i = 0; i < 8; i++) {
        Pos nt = new Pos(curr.y + pos[i].y,curr.x + pos[i].x);
        if (0 > nt.y || nt.y >= h || 0 > nt.x || nt.x >= w) continue;
        if (vi[nt.y][nt.x] || map[nt.y][nt.x] == 0) continue;
        q.offer(nt);
      }
    }
  }

  public static int f(int[][] map) {
    for (int i = 0; i < h; i++) {
      Arrays.fill(vi[i], false);
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
      for (int k = 0; k < w; k++) {
        if (!vi[i][k] && map[i][k] == 1) {
          ans++;
          bfs(map, new Pos(i, k));
        }
      }
    }

    return ans;
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st;
    while (true) {
      st = new StringTokenizer(br.readLine());
      w = Integer.parseInt(st.nextToken());
      h = Integer.parseInt(st.nextToken());
      if (w == 0 && h == 0) {
        bw.flush();
        return;
      }
      int[][] map = new int[h][w];
      for (int i = 0; i < h; i++) {
        st = new StringTokenizer(br.readLine());
        for (int k = 0; k < w; k++) {
          map[i][k] = Integer.parseInt(st.nextToken());
        }
      }
      bw.write(f(map) + "\n");
    }
  }
}
