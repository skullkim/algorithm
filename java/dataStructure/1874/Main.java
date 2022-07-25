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
        n = Integer.parseInt(r.readLine());
        for (int i = 1; i <= n; i++) {
            ex.add(Integer.parseInt(r.readLine()));
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
