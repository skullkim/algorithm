import java.io.*;
import java.util.*;
import java.util.function.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static int stp, target;
  static byte[] vi = new byte[200001];

  static class Pos {
    List<Integer> path; int p; int times;
    Pos(int p) {
      path = new ArrayList<Integer>(); this.p = p;
      times = 0;
      path.add(p);
    }
    Pos(int p, List<Integer> path, int times) {
      this.p = p; this.path = path; this.times = times;
    }
  }
  static List<Function<Integer, Integer>> moves = new ArrayList<>();
  static {
    moves.add((a) -> a - 1);
    moves.add((a) -> a + 1);
    moves.add((a) -> a * 2);
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    Arrays.fill(vi, (byte)0);
    stp = Integer.parseInt(st.nextToken());
    target = Integer.parseInt(st.nextToken());
    
    Queue<Pos> q = new LinkedList<>();
    q.add(new Pos(stp));
    vi[stp] = 1;
    while (!q.isEmpty()) {
      Pos curr = q.peek();
      q.poll();
      if (curr.p == target) {
        bw.write(curr.times + "\n");
        for (int i = 0; i < curr.path.size(); i++) {
          bw.write(curr.path.get(i) + " ");
        }
        bw.flush();
        return;
      }

      for (int i = 0; i < 3; i++) {
        int nt = moves.get(i).apply(curr.p);
        if (nt > 200000 || vi[nt] == 1) continue;
        List<Integer> tmp = new ArrayList<Integer>(curr.path);
        tmp.add(nt);
        q.add(new Pos(nt, tmp, curr.times + 1));
        vi[nt] = 1;
      }
    }
  }
}
