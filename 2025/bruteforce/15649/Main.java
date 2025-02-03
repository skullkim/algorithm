import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static int n, m;

  static void f(List<Integer> list, boolean[] vi) throws IOException {
    if (list.size() == m) {
      for (int i = 0; i < m; i++) {
        bw.write(list.get(i) + " ");
      }
      bw.write("\n");
      return;
    }

    for (int i = 1; i <= n; i++) {
      if (vi[i]) continue;
      vi[i] = true;
      list.add(i);
      f(list, vi);
      vi[i] = false;
      list.remove(list.size() - 1);
    }
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    boolean[] vi = new boolean[n + 1];
    Arrays.fill(vi, 0, n + 1, false);
    f(new ArrayList<>(), vi);
    bw.flush();
  }
}
