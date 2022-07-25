import java.util.*;
import java.io.*;

public class Main {

    static int n;
    static String b;
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(r.readLine());
        n = Integer.parseInt(st.nextToken());
        for  (int k = 0; k < n; k++) {
            st = new StringTokenizer(r.readLine());
            b = st.nextToken();
            int ans = 0;
            for (int i = 0; i < b.length(); i++) {
                if (b.charAt(i) == '(') ans++;
                else if (b.charAt(i) == ')') ans--;
                if (ans < 0) break;
            }
            if (ans == 0) w.write("YES\n");
            else w.write("NO\n");
        }
        w.flush();
    }
}
