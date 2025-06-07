import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static class Pos {
    int y; int x; int d;
    Pos(int y, int x, int d) {
      this.y = y; this.x = x; this.d = d;
    }
    Pos(int y, int x) {
      this(y, x, 0);
    }
  }
  static Pos[] dir = {new Pos(-1, 0), new Pos(1, 0), new Pos(0, -1), new Pos(0, 1)};
  static int[][] g = new int[1000][1000];
  static int day, yy, xx, ts;
  static boolean[][] vi = new boolean[1000][1000];

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    xx = Integer.parseInt(st.nextToken());
    yy = Integer.parseInt(st.nextToken());

    Queue<Pos> q = new LinkedList<>();
    for (int i = 0; i < yy; i++) {
      st = new StringTokenizer(br.readLine());
      for (int k = 0; k < xx; k++) {
        g[i][k] = Integer.parseInt(st.nextToken());
        if (g[i][k] == 0) ts++;
        else if (g[i][k] == 1) {
          q.offer(new Pos(i, k));
          vi[i][k] = true;
        }
      }
    }

    if (ts == 0) {
      bw.write("0");
      bw.flush();
      return;
    }

    while (!q.isEmpty()) {
      Pos curr = q.peek();
      q.poll();

      for (int i = 0; i < 4; i++) {
        Pos nt = new Pos(curr.y + dir[i].y, curr.x + dir[i].x, curr.d + 1);
        if (0 > nt.y || nt.y >= yy || 0 > nt.x || nt.x >= xx) continue;
        if (vi[nt.y][nt.x] || g[nt.y][nt.x] == -1) continue;
        ts--;
        vi[nt.y][nt.x] = true;

//        System.out.println(curr.y + ", " + curr.x + ", " + curr.d);
//        for (int ii = 0; ii < yy; ii++) {
//          for (int k = 0; k < xx; k++) {
//            System.out.print(vi[ii][k] + " ");
//          }
//          System.out.println();
//        }
//          System.out.println();

        if(ts == 0) {
          bw.write(curr.d + 1 + "");
         }
        q.offer(nt);
      }
      if (ts == 0) break;
    }

    if (ts != 0) {
      bw.write("-1");
    }
    bw.flush();
  }
}
