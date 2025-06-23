import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

  static void swap(int[][] arr, int y1, int x1, int y2, int x2) {
    int tmp = arr[y1][x1];
    arr[y1][x1] = arr[y2][x2];
    arr[y2][x2] = tmp;
  }

  static void print(int[][] arr, int ys, int xs) {
    for (int i = 1; i <= ys; i++) {
      for (int k = 1; k <= xs; k++) {
        System.out.print(arr[i][k] + " ");
      }
      System.out.println();
    }
      System.out.println();
  }

  static class Dir {
    int r, c, s;
    Dir(int r, int c, int s) {
      this.r = r; this.c = c; this.s = s;
    }
  }

  static int ys, xs, rot, ans = 987654321;
  static int[][] arr = new int[51][51];
  static boolean[] vi = new boolean[8];

  static void f(List<Dir> org, List<Dir> curr) {
    if (org.size() == curr.size()) {
      for (Dir d : curr) {
        int r, c, s;
        r = d.r;
        c = d.c;
        s = d.s;

        int sy = r - s, sx = c - s;
        int ey = r + s, ex = c + s;
        while ((sx != ex) && (sy != ey)) {
          for (int i = sx; i <= ex; i++) {
            swap(arr, sy, sx, sy, i);
          }
          for (int i = sy + 1; i <= ey; i++) {
            swap(arr, sy, sx, i, ex);
          }
          for (int i = ex - 1; i >= sx; i--) {
            swap(arr, sy, sx, ey, i);
          }
          for (int i = ey - 1; i >= sy; i--) {
            swap(arr, sy, sx, i, sx);
          }
          sx++; sy++;
          ex--; ey--;
        }

        for (int i = 1; i <= ys; i++) {
          int sum = 0;
          for (int k = 1; k <= xs; k++) {
            sum += arr[i][k];
          }
          ans = Math.min(ans, sum);
        }
      }
    }
    
    for (int i = 0; i < org.size(); i++) {
      if (vi[i]) continue;
      curr.add(org.get(i));
      vi[i] = true;
      f(org, curr);
      vi[i] = false;
      curr.remove(curr.size() - 1);
    }
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    ys = Integer.parseInt(st.nextToken());
    xs = Integer.parseInt(st.nextToken());
    rot = Integer.parseInt(st.nextToken());

    for (int i = 1; i <= ys; i++) {
      st = new StringTokenizer(br.readLine());
      for (int k = 1; k <= xs; k++) {
        arr[i][k] = Integer.parseInt(st.nextToken());
      }
    }

    List<Dir> li = new ArrayList<>();
    for (int i = 0; i < rot; i++) {
      int r, c, s;
      st = new StringTokenizer(br.readLine());
      r = Integer.parseInt(st.nextToken());
      c = Integer.parseInt(st.nextToken());
      s = Integer.parseInt(st.nextToken());
      li.add(new Dir(r, c, s));
    }
    f(li, new ArrayList<Dir>());
    bw.write(ans + "");
    bw.flush();
  }
}
