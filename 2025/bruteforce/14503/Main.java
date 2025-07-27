import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static int row, col;
  static int[][] g = new int[50][50];
  static int EMPTY = 0;
  static int WALL = 1;
  static int CLEANED = 2;
  static int N = 0, E = 1, S = 2, W = 3;
  static class Pos {
    int y; int x;
    Pos(int y, int x) {
      this.y = y; this.x = x;
    }
  }
  static Pos[] DIR = {new Pos(-1, 0), new Pos(0, 1), new Pos(1, 0), new Pos(0, -1)};

  static Boolean allCleaned(Pos curr) {
    for (int i = 0; i < 4; i++) {
      Pos nt = new Pos(curr.y + DIR[i].y, curr.x + DIR[i].x);
      if (g[nt.y][nt.x] == EMPTY) return false;
    }
    return true;
  }

  static int rotDir(int dir) {
    if (dir == N) return W;
    else if (dir == W) return S;
    else if (dir == S) return E;
    else return N;
  }

  static Pos backPos(int dir, Pos currPos) {
    Pos nt = null;
    if (dir == N) {
      Pos tmp = new Pos(currPos.y + DIR[S].y, currPos.x + DIR[S].x);
      if (g[tmp.y][tmp.x] != WALL) nt = tmp;
    }
    else if (dir == E) {
      Pos tmp = new Pos(currPos.y + DIR[W].y, currPos.x + DIR[W].x);
      if (g[tmp.y][tmp.x] != WALL) nt = tmp;
    }
    else if (dir == S) {
      Pos tmp = new Pos(currPos.y + DIR[N].y, currPos.x + DIR[N].x);
      if (g[tmp.y][tmp.x] != WALL) nt = tmp;
    }
    else if (dir == W) {
      Pos tmp = new Pos(currPos.y + DIR[E].y, currPos.x + DIR[E].x);
      if (g[tmp.y][tmp.x] != WALL) nt = tmp;
    }

    return nt;
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    row = Integer.parseInt(st.nextToken());
    col = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());
    Pos stPos = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
    int stDir = Integer.parseInt(st.nextToken());
    for (int r = 0; r < row; r++) {
      st = new StringTokenizer(br.readLine());
      for (int c = 0; c < col; c++) {
        g[r][c] = Integer.parseInt(st.nextToken());
      }
    }

    int ans = 0;
    Pos curr = new Pos(stPos.y, stPos.x);
    int currDir = stDir;
    while (true) {
      if (g[curr.y][curr.x] == EMPTY) {
        g[curr.y][curr.x] = CLEANED;
        ans++;
      }

      if (allCleaned(curr) == true) {
        Pos ntPos = backPos(currDir, curr);
        if (ntPos != null) {
          curr = ntPos;
          continue;
        } else {
          break;
        }
      } else {
        currDir = rotDir(currDir);
        Pos nt = new Pos(curr.y + DIR[currDir].y, curr.x + DIR[currDir].x);
        if (g[nt.y][nt.x] == EMPTY) {
          curr = nt;
        }
        continue;
      }
    }
    bw.write(ans + "");
    bw.flush();
  }
}
