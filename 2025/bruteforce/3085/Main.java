import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static int size;
  static int ans = -1;

  static class Pos {
    int y; int x;
    Pos(int y, int x) {
      this.y = y; this.x = x;
    }
  }
  static Pos[] dir = {new Pos(-1, 0), new Pos(1, 0), new Pos(0, -1), new Pos(0, 1)};

  static int findAns(Pos p1, Pos p2, char[][] g) {
    char tmp = g[p1.y][p1.x];
    g[p1.y][p1.x] = g[p2.y][p2.x];
    g[p2.y][p2.x] = tmp;

    int tmpMax = 0;
    int cnt = 0;
    char prev = 'a';
    for (int i = 0; i < size; i++) {
      for (int k = 0; k < size; k++) {
        if (prev == g[i][k]) {
          cnt++;
        } else {
          cnt = 1;
          prev = g[i][k];
        }
        tmpMax = Math.max(tmpMax, cnt);
      }
      cnt = 0;
      prev = 'a';
    }

    for (int i = 0; i < size; i++) {
      prev = 'a';
      cnt = 0;
      for (int k = 0; k < size; k++) {
        if (prev == g[k][i]) {
          cnt++;
        } else {
          prev = g[k][i];
          cnt = 1;
        }
        tmpMax = Math.max(tmpMax, cnt);
      }
    }

    return tmpMax;
  }

  static void f(Pos curr, char[][] g) {
    for (int i = 0; i < 4; i++) {
      Pos nt = new Pos(curr.y + dir[i].y, curr.x + dir[i].x);
      if (0 > nt.y || nt.y >= size || 0 > nt.x || nt.x >= size) continue;
      ans = Math.max(ans, findAns(curr, nt, g));
    }
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    size = Integer.parseInt(st.nextToken());
    char[][] g = new char[size][size];
    for (int i = 0; i < size; i++) {
      char[] arr = br.readLine().toCharArray();
      for (int k = 0; k < arr.length; k++) {
        g[i][k] = arr[k];
      }
    }

    ans = findAns(new Pos(0, 0), new Pos(0, 0), g);
    for (int i = 0; i < size; i++) {
      for (int k = 0; k < size; k++) {
        f(new Pos(i, k), g);
      }
    }

    bw.write(ans + "");
    bw.flush();
  }
}
