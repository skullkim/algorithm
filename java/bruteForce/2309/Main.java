import java.util.*;
import java.io.*;

public class Main {

    static ArrayList<Integer> ans = new ArrayList<>();
    static ArrayList<Integer> arr = new ArrayList<>();
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
    static boolean isAns = false;

    static void f(int idx) {
        if (ans.size() == 7) {
            int s = 0;
            for (Integer nn : ans) s += nn;
            if (s == 100) isAns = true;
            return;
        }

        for (int i = idx; i < 9; i++) {
            ans.add(arr.get(i));
            f(i + 1);
            if (isAns) return;
            ans.remove(ans.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        for (int i = 0; i < 9; i++) {
            st = new StringTokenizer(r.readLine());
            arr.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(arr);

        f(0);
        for (Integer nn : ans) {
            w.write(nn + "\n");
        }
        w.flush();
    }

}
