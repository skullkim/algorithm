import java.io.*;
import java.util.*;
import java.util.function.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static int stp, target;
  static byte[] vi = new byte[200001];
  static int path[] = new int[10010];

  static class Pos {
    List<Integer> path; int p; int times;
    Pos(int p) {
      this.p = p;
      times = 0;
    }
    Pos(int p, int times) {
      this.p = p; this.times = times;
    }
  }

  static void print(int idx) throws IOException {
    if (idx != stp) {
      print(path[idx]);
    }
    bw.write(idx + " ");
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
        print(target);
        bw.flush();
        return;
      }

      int[] moves = {curr.p - 1, curr.p + 1, curr.p * 2};
      for (int i = 0; i < 3; i++) {
        int nt = moves[i];
        if (nt > 200000 || vi[nt] == 1) continue;
        path[nt] = curr.p;
        q.add(new Pos(nt, curr.times + 1));
        vi[nt] = 1;
      }
    }
  }
}
