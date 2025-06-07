import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static int t, brokens, nBtnLen;
  static int[] nBtns;
  static int nearNum = -1, minClick = 987654321;
  static boolean[] vi = new boolean[500005];

  static int isBk(int num, boolean[] bk) {
    if (num == 0 && !bk[0]) {
      return 1;
    }
    int sz = 0;
    while (num > 0) {
      int n = num % 10;
      if (bk[n]) return 0;
      num = num / 10;
      sz++;
    }
    return sz;
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    t = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());
    brokens = Integer.parseInt(st.nextToken());

    boolean[] bk = new boolean[10];
    if (brokens >= 1) {
      st = new StringTokenizer(br.readLine());
      int[] bkBtns = new int[brokens];
      for (int i = 0; i < brokens; i++) {
        bkBtns[i] = Integer.parseInt(st.nextToken());
      }

      Arrays.fill(bk, false);
      for (int i = 0; i < bkBtns.length; i++) {
        bk[bkBtns[i]] = true;
      }
    }

    minClick = Math.abs(t - 100);
    for (int i = 0; i <= 1000000; i++) {
      int numClk = isBk(i, bk);
      if (numClk == 0) continue;
      int g = Math.abs(i - t);
      minClick = Math.min(minClick, g + numClk);
    }

    bw.write(minClick + "");
    bw.flush();
  }
}
