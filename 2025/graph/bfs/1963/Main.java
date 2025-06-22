import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static boolean[] pn = new boolean[10010];
  static int qs;

  static class Tern {
    int n; int t;
    Tern(int n) {
      this(n, 0);
    }
    Tern(int n, int t) {
      this.n = n; this.t = t;
    }
  }

  static boolean f(int n1, int n2) {
    char[] ns1 = (n1 + "").toCharArray();
    char[] ns2 = (n2 + "").toCharArray();

    return (ns1[0] != ns2[0] && ns1[1] == ns2[1] && ns1[2] == ns2[2] && ns1[3] == ns2[3])
    || (ns1[0] == ns2[0] && ns1[1] != ns2[1] && ns1[2] == ns2[2] && ns1[3] == ns2[3])
    || (ns1[0] == ns2[0] && ns1[1] == ns2[1] && ns1[2] != ns2[2] && ns1[3] == ns2[3])
    || (ns1[0] == ns2[0] && ns1[1] == ns2[1] && ns1[2] == ns2[2] && ns1[3] != ns2[3]);

  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    qs = Integer.parseInt(st.nextToken());

    pn[0] = true;
    pn[1] = true;
    List<Integer> candi = new ArrayList<>();
    for (int i = 2; i < 10010; i++) {
      if (pn[i]) continue;
      if (1000 <= i && i <= 9999) candi.add(i);
      for (int k = i + i; k < 10010; k += i) {
        pn[k] = true;
      }
    }

    List<List<Integer>> g = new ArrayList<>(10010);
    for (int i = 0; i < 10010; i++) {
      g.add(new ArrayList<Integer>());
    }

    for (int i = 0; i < candi.size(); i++) {
      for (int k = i + 1; k < candi.size(); k++) {
        int n1 = candi.get(i), n2 = candi.get(k);
        if (!f(n1, n2)) continue;
        g.get(n1).add(n2);
        g.get(n2).add(n1);
      }
    }

    while (qs-- > 0) {
      int start, target;
      st = new StringTokenizer(br.readLine());
      start = Integer.parseInt(st.nextToken());
      target = Integer.parseInt(st.nextToken());

      boolean[] vi = new boolean[10010] ;
      Arrays.fill(vi, false);
      Queue<Tern> q = new LinkedList<>();
      boolean hasAns = false;
      q.add(new Tern(start));
      while (!q.isEmpty()) {
        Tern curr = q.peek();
        q.poll();
        vi[curr.n] = true;
        if (curr.n == target) {
          bw.write(curr.t + "\n");
          hasAns = true;
          break;
        }

        for (int i = 0; i < g.get(curr.n).size(); i++) {
          int nt = g.get(curr.n).get(i);
          if (vi[nt]) continue;
          q.add(new Tern(nt, curr.t + 1));
        }
      }
      if (!hasAns) bw.write("Impossible\n");
    }
    bw.flush();
  }
}
