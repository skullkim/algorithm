import java.io.*;
import java.util.*;

public class Main2 {

    static int numbers;
    static final int MAX = 1_010;
    static int[] sequence = new int[MAX];
    static int[] cache = new int[MAX];
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        for (int i = 0; i < MAX; i++) cache[i] = 1;
        StringTokenizer st = new StringTokenizer(r.readLine());
        numbers = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(r.readLine());
        for (int i = 0; i < numbers; i++) {
            sequence[i] = Integer.parseInt(st.nextToken());
        }

        int ans = 0;
        for (int now = 0; now < numbers; now++) {
            for (int before = 0; before < now; before++) {
                if (sequence[before] >= sequence[now]) continue;
                cache[now] = Math.max(cache[before] + 1, cache[now]);
            }
            ans = Math.max(ans, cache[now]);
        }
        w.write(ans + "\n");
        w.flush();
    }
}
