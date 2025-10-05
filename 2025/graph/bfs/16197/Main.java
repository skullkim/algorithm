import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static char WALL = '#', EMPTY = '.', COIN = 'o';
  static char[][] g = new char[21][21];
  static int row, col;
  static class Pos {
    int y; int x; int times = 0;
    Pos(int y, int x) {
      this.y = y; this.x = x;
    }
    Pos(int y, int x, int times) {
      this.y = y; this.x = x; this.times = times;
    }
  }
  static Pos[] DIR = {new Pos(-1, 0), new Pos(1, 0), new Pos(0, 1), new Pos(0, -1)};
  static byte[][][][] vi = new byte[21][21][21][21];

  public static void main(String[] args) throws IOException {
    for (int i = 0; i < 20; i++) {
      for (int ii = 0; ii < 20; ii++) {
        for (int iii = 0; iii < 20; iii++) {
          Arrays.fill(vi[i][ii][iii], (byte)0);
        }
      }
    }

    StringTokenizer st = new StringTokenizer(br.readLine());
    Pos[] stp = new Pos[2];
    int stpIdx = 0;

    row = Integer.parseInt(st.nextToken());
    col = Integer.parseInt(st.nextToken());
    for (int i = 0; i < row; i++) {
      st = new StringTokenizer(br.readLine());
      char[] tmp = st.nextToken().toCharArray();
      for (int k = 0; k < col; k++) {
        g[i][k] = tmp[k];
        if (g[i][k] == COIN) {
          stp[stpIdx++] = new Pos(i, k);
          g[i][k] = EMPTY;
        }
      }
    }

    int ans = -1;
    Queue<Pos[]> q = new LinkedList<>();
    q.add(stp);
    while (!q.isEmpty()) {
      Pos[] curr = q.poll();

      Pos p1 = curr[0], p2 = curr[1];
//      System.out.println(p1.y + ", " + p1.x + ", " + p1.times);
//      System.out.println(p2.y + ", " + p2.x + ", " + p2.times);
//      System.out.println("==========");
      if (p1.times >= 11 || p2.times >= 11) {
        break;
      } else if (p1.y == -1 ^ p2.y == -1) {
        ans = p1.times;
        break;
      }

      for (int i = 0; i < 4; i++) {
        Pos[] nt = {
          new Pos(p1.y + DIR[i].y, p1.x + DIR[i].x, p1.times + 1),
          new Pos(p2.y + DIR[i].y, p2.x + DIR[i].x, p2.times + 1)
        };
        if (0 > nt[0].y || nt[0].y >= row || 0 > nt[0].x || nt[0].x >= col) {
          nt[0].y = -1; nt[0].x = -1;
        } else if(!canMove(nt[0])) {
          nt[0].y = p1.y; nt[0].x = p1.x;
        }
        if (0 > nt[1].y || nt[1].y >= row || 0 > nt[1].x || nt[1].x >= col) {
          nt[1].y = -1; nt[1].x = -1;
        } else if (!canMove(nt[1])) {
          nt[1].y = p2.y; nt[1].x = p2.x;
        }

        if (nt[0].y == -1 && nt[0].x == -1 && nt[1].y == -1 && nt[1].x == -1) {
          continue;
        }

        if (nt[0].y >= 0 && nt[0].x >= 0 && nt[1].y >= 0 && nt[1].x >= 0) {
          if (vi[nt[0].y][nt[0].x][nt[1].y][nt[1].x] == 1) continue;
          vi[nt[0].y][nt[0].x][nt[1].y][nt[1].x] = 1;
        }

        q.add(nt);
      }
    }

    bw.write(ans + "");
    bw.flush();
  }

  static boolean canMove(Pos p) {
    int pp = g[p.y][p.x];
    if (pp == WALL) return false;
    return true;
  }
}
