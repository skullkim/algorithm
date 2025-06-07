import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static char[] a;
  static char[] b;
  static int bInt, bLen;
  static int ans = -1;

  static void f(boolean[] vi, String c) {
    if (c.length() > bLen) return;
    //if (c.length() <= a.length && c.length() == b.length) {
    if (c.length() == a.length) {
      int cc = Integer.parseInt(c);
      if (cc >= bInt) return;
      //System.out.println(c);
      ans = Math.max(ans, cc);
      return;
    }
    if (c.length() == bLen) return;

    for (int i = 0; i < a.length; i++) {
      if (c.length() == 0 && a[i] == '0') continue;
      if (vi[i]) continue;
      vi[i] = true;
      f(vi, c + a[i]);
      vi[i] = false;
    }
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    a = st.nextToken().toCharArray();
    String tmp = st.nextToken();
    b = tmp.toCharArray();
    bLen = b.length;
    bInt = Integer.parseInt(tmp);
    
    boolean[] vi = new boolean[a.length];
    f(vi, "");
    bw.write(ans + "");
    bw.flush();
 }
}
