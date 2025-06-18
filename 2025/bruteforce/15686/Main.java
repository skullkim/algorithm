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

    @Override
    public String toString() {
      return "y: " + y + ", x: " + x + "| ";
    }
  }
  static List<Pos> h = new ArrayList<>();
  static List<Pos> c = new ArrayList<>();
  static int n, m, ans = 987654321;

  public static void f(List<Pos> curr, int idx) {
    if (curr.size() > m) return;

    if (curr.size() >= 1) {
      int tcl = 0;
      for (int i = 0; i < h.size(); i++) {
        int tmpMin = 987654321;
        for (int k = 0; k < curr.size(); k++) {
          Pos hp = h.get(i);
          Pos cp = curr.get(k);
          int cl = Math.abs(hp.y - cp.y) + Math.abs(hp.x - cp.x);
          tmpMin = Math.min(tmpMin, cl);
        }
        tcl += tmpMin;
      }
      ans = Math.min(ans, tcl);
    }

    for (int i = idx; i < c.size(); i++) {
      curr.add(c.get(i));
      f(curr, i + 1);
      curr.remove(curr.size() - 1);
    }
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    for (int i = 1; i <= n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int k = 1; k <= n; k++) {
        int a = Integer.parseInt(st.nextToken());
        if (a == 1) {
          h.add(new Pos(i, k));
        } else if (a == 2) {
          c.add(new Pos(i, k));
        }
      }
    }
    f(new ArrayList<Pos>(), 0);

    bw.write(ans + "");
    bw.flush();
  }
}
