import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static ArrayList<ArrayList<Integer>> g = new ArrayList<>();
  static int nodes, edges, start;

  static void dfs(int curN, boolean[] vi) throws IOException {
    if (vi[curN]) return;
    vi[curN] = true;
    bw.write(curN + " ");

    ArrayList<Integer> gg = g.get(curN);
    for (int i = 0; i < gg.size(); i++) {
      dfs(gg.get(i), vi);
    }
  }

  static void bfs(int curN, boolean[] vi) throws IOException {
    Queue<Integer> q = new LinkedList();
    q.offer(curN);
    while (!q.isEmpty()) {
      int cur = q.peek();
      q.poll();
      if (vi[cur]) continue;
      vi[cur] = true;
      bw.write(cur + " ");

      List<Integer> gg = g.get(cur);
      for (int i = 0; i < gg.size(); i++) {
        q.offer(gg.get(i));
      }
    }
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    nodes = Integer.parseInt(st.nextToken());
    edges = Integer.parseInt(st.nextToken());
    start = Integer.parseInt(st.nextToken());

    for (int i = 0; i <= nodes; i++) {
      g.add(new ArrayList<>());
    }

    for (int i = 0; i < edges; i++) {
      st = new StringTokenizer(br.readLine());
      int n1 = Integer.parseInt(st.nextToken());
      int n2 = Integer.parseInt(st.nextToken());
      g.get(n1).add(n2);
      g.get(n2).add(n1);
    }

    for (int i = 1; i < nodes; i++) {
      Collections.sort(g.get(i));
    }

    boolean[] vi = new boolean[nodes + 5];
    Arrays.fill(vi, false);
    dfs(start, vi);
    bw.write("\n");

    Arrays.fill(vi, false);
    bfs(start, vi);
    bw.flush();
 } 
}
