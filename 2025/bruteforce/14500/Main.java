import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static class Pos {
    int y; int x;
    public Pos(int y, int x) {
      this.y = y; this.x = x;
    }
  };

  static Pos[][] SHAPE = {
    // ****
    {new Pos(0, 0), new Pos(0, 1), new Pos(0, 2), new Pos(0, 3)},
    {new Pos(0, 0), new Pos(1, 0), new Pos(2, 0), new Pos(3, 0)},
    // **
    // **
    {new Pos(0, 0), new Pos(0, 1), new Pos(1, 0), new Pos(1, 1)},
    //*
    //*
    //* *
    {new Pos(0, 0), new Pos(1, 0), new Pos(2, 0), new Pos(2, 1)},
    {new Pos(0, 0), new Pos(0, -1), new Pos(0, -2), new Pos(1, -2)},
    {new Pos(0, 0), new Pos(-1, 0), new Pos(-2, 0), new Pos(-2, -1)},
    {new Pos(0, 0), new Pos(0, 1), new Pos(0, 2), new Pos(-1, 2)},
    // *
    // * *
    //   *
    {new Pos(0, 0), new Pos(1, 0), new Pos(1, 1), new Pos(2, 1)},
    {new Pos(0, 0), new Pos(0, -1), new Pos(1, -1), new Pos(1, -2)},
    // ***
    //  *
    {new Pos(0, 0), new Pos(0, 1), new Pos(0, 2), new Pos(1, 1)},
    {new Pos(0, 0), new Pos(1, 0), new Pos(2, 0), new Pos(1, -1)},
    {new Pos(0, 0), new Pos(0, -1), new Pos(0, -2), new Pos(-1, -1)},
    {new Pos(0, 0), new Pos(-1, 0), new Pos(-1, 1), new Pos(-2, 0)}
  };


  static int row, col;
  static int[][] g = new int[500][500];

  static boolean isOut(int y, int x) {
    return 0 > y || y >= row || 0 > x || x >= col;
  }

  static Pos genePos(int r, int c, int sIdx, int idx) {
    r = r + SHAPE[sIdx][idx].y;
    c = c + SHAPE[sIdx][idx].x;
    if (isOut(r, c)) return null;
    return new Pos(r, c);
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    row = Integer.parseInt(st.nextToken());
    col = Integer.parseInt(st.nextToken());
    for (int i = 0; i < row; i++) {
      st = new StringTokenizer(br.readLine());
      for (int k = 0; k < col; k++) {
        g[i][k] = Integer.parseInt(st.nextToken());
      }
    }

    int ans = -1;
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        for (int s = 0; s < 13; s++) {
          Pos p1 = new Pos(r, c);
          Pos p2 = genePos(r, c, s, 1);
          Pos p3 = genePos(r, c, s, 2);
          Pos p4 = genePos(r, c, s, 3);
          if (p2 == null || p3 == null || p4 == null) continue;

          int tmp = g[p1.y][p1.x] + g[p2.y][p2.x] + g[p3.y][p3.x] + g[p4.y][p4.x];
//          if (r == 0 && c == 4) {
//            System.out.println(p1.y + ", " + p1.x);
//            System.out.println(p2.y + ", " + p2.x);
//            System.out.println(p3.y + ", " + p2.x);
//            System.out.println(p4.y + ", " + p4.x);
//            System.out.println(tmp);
//            System.out.println("=====================");
//          }
          ans = Math.max(ans, tmp);
        }
      }
    }

    bw.write(ans + "");
    bw.flush();
  }
}
