import java.util.*;
import java.io.*;

public class Main {

    static LinkedList<Integer> l = new LinkedList<>();
    static int n, k;
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(r.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++) {
            l.add(i);
        }
        ArrayList<Integer> ans = new ArrayList<>();
        int idx = -1;
        while (!l.isEmpty()) {
            for (int kk = 0; kk < k; kk++) {
               idx++;
               if (idx >= l.size()) {
                    idx = 0;
                }
            }
            if (idx == -1) idx = 0;
            ans.add(l.get(idx));
            l.remove(idx--);
        }
        w.write("<");
        for (int i = 0; i < ans.size() - 1; i++) {
            w.write(ans.get(i) + ", ");
        }
        w.write(ans.get(ans.size() - 1) + ">");
        w.flush();
    }
}
