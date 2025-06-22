import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static List<ArrayList<Integer>> p;
  static boolean[][] vi = new boolean[4001][4001];
  static int nodes, edges;

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    nodes = Integer.parseInt(st.nextToken());
    edges = Integer.parseInt(st.nextToken());

    p = new ArrayList<ArrayList<Integer>>(nodes + 1);
    for (int i = 0; i <= nodes; i++) {
      p.add(new ArrayList<Integer>());
    }

    int n1, n2;
    for (int i = 0; i < edges; i++) {
      st = new StringTokenizer(br.readLine());
      n1 = Integer.parseInt(st.nextToken());
      n2 = Integer.parseInt(st.nextToken());
      if (!vi[n1][n2])
      p.get(n1).add(n2);
      p.get(n2).add(n1);
      vi[n1][n2] = true;
      vi[n2][n1] = true;
    }

    int f1, f2, f3;
    int ans = 987654321;
    for (int n = 1; n <= nodes; n++) {
      if (p.get(n).size() <= 1) continue;
      List<Integer> curr = p.get(n);
      f1 = n;
      for (int i = 0; i < curr.size(); i++) {
        f2 = curr.get(i);
        for (int k = i + 1; k < curr.size(); k++) {
          f3 = curr.get(k);
          if (!vi[f1][f2] || !vi[f1][f3] || !vi[f2][f3]) continue;
          int t = (p.get(f1).size() - 2) + (p.get(f2).size() - 2) + (p.get(f3).size() - 2);
          ans = Math.min(ans, t);
        }
      }
    }

    if (ans == 987654321) {
      bw.write("-1");
    } else {
      bw.write(ans + "");
    }
    bw.flush();
  }
}
