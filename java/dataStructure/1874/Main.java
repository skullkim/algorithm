import java.util.*;
import java.io.*;

public class Main {

    static int n;
    static ArrayList<Integer> ex = new ArrayList<>();
    static Stack<Integer> a = new Stack<>();
    static Stack<Integer> b = new Stack<>();
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(r.readLine());
        n = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(r.readLine());
            ex.add(Integer.parseInt(st.nextToken()));
        }
        int idx = 0;
        String ans = "";
        for (int i = 1; i <= n; i++) {
            a.push(i);
            ans += "+";
            while(!a.empty() && a.peek() == ex.get(idx)) {
                b.add(a.peek());
                a.pop();
                ans += "-";
                idx++;
            }
        }
        if (!a.empty()) {
            w.write("NO\n");
            w.flush();
            return;
        }
        for (int i = 0; i < ans.length(); i++) {
            w.write(ans.charAt(i) + "\n");
        }
        w.flush();
    }
}
