import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    int q = Integer.parseInt(st.nextToken());
    while (q-- > 0) {
      st = new StringTokenizer(br.readLine());
      int lastX = Integer.parseInt(st.nextToken());
      int lastY = Integer.parseInt(st.nextToken());
      int tx = Integer.parseInt(st.nextToken());
      int ty = Integer.parseInt(st.nextToken());

      int x = 1, y = 1;
      int cnt = 1;
      while (true) {
        if (x < lastX) x++;
        else x = 1;

        if (y < lastY) y++;
        else y = 1;

        cnt++;
        if (x == tx && y == ty) {
          bw.write(cnt + "\n");
          break;
        }
        if (x == lastX && y == lastY) {
          bw.write("-1\n");
          break;
        }
      }
    }
    bw.flush();
  }
}
