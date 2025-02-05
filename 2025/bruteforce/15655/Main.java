import java.io.*;
import java.util.*;

public class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static int nums, sz;
  static List<Integer> arr = new ArrayList<>();

  static void f(List<Integer> ans, int idx) throws IOException {
    if (ans.size() == sz) {
      for (int i = 0; i < sz; i++) {
        bw.write(ans.get(i) + " ");
      }
      bw.write("\n");
      return;
    }

    for (int i = idx; i < nums; i++) {
      ans.add(arr.get(i));
      f(ans, i + 1);
      ans.remove(ans.size() - 1);
    }
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());
    nums = Integer.parseInt(st.nextToken());
    sz = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < nums; i++) {
      int a = Integer.parseInt(st.nextToken());
      arr.add(a);
    }
    Collections.sort(arr);

    f(new ArrayList<>(), 0);
    bw.flush();
  }
}
