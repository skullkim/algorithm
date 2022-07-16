import java.util.*;
import java.io.*;

public class Main {

    static int from, to;
    static final int MAX = 1_000_010;
    static boolean[] arr = new boolean[MAX];
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(r.readLine());
        from = Integer.parseInt(st.nextToken());
        to = Integer.parseInt(st.nextToken());
        arr[1] = true; arr[0] = true;
        for (int i = 2; i <= to; i++) {
            if (arr[i]) continue;
            for (int k = i + i; k <= to; k += i) {
                if (arr[k]) continue;
                arr[k] = true;
            }
        }

        for (int i = from; i <= to; i++) {
            if (!arr[i]) w.write(i + "\n");
        }
        w.flush();
    }
}
