import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static char[] a;
  static char[] b;
  static int ans = -1;

  static void f(boolean[] vi, String c) {
    if (c.length() > b.length) return;
    if (c.length() == a.length && c.length() == b.length) {
      //System.out.println(c);
      ans = Math.max(ans, Integer.parseInt(c));
      return;
    }
    if (c.length() == b.length) return;

    for (int i = 0; i < a.length; i++) {
      if (c.length() == 0 && a[i] == '0') continue;
      if (a[i] > b[c.length()] || vi[i]) continue;
      vi[i] = true;
      f(vi, c + a[i]);
      vi[i] = false;
    }
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    a = st.nextToken().toCharArray();
    b = st.nextToken().toCharArray();
    
    boolean[] vi = new boolean[a.length];
    f(vi, "");
    bw.write(ans + "");
    bw.flush();
 }
}
