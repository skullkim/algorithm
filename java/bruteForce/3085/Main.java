import java.io.*;
import java.util.*;

public class Main {

    static int s, ans;
    static String[][] g = new String[50][50];
    static int[] dy = {0, 1};
    static int[] dx = {1, 0};
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void f() {
        for (int i = 0; i < s; i++) {
            for (int k = 0; k < s; k++) {
                for (int n = 0; n < 2; n++) {
                    int nx = k + dx[n];
                    int ny = i + dy[n];
                    if (0 > ny || ny >= s || 0 > nx || nx >= s) continue;
                    String currNode = g[i][k];
                    String nextNode = g[ny][nx];
                    if (currNode == nextNode) continue;
                    swap(i, k, ny, nx);
                    checkEatable();
                    swap(i, k, ny, nx);
                }
            }
        }
    }

    public static void checkEatable() {
        int same = 0;

        for (int i = 0; i < s; i++) {
            String t = g[i][0];
            same = 0;
            for (int k = 0; k < s; k++) {
                if (t.equals(g[i][k])) same++;
                else {
                    t = g[i][k];
                    same = 1;
                }
                ans = Math.max(ans, same);
            }

            t = g[0][i];
            same = 0;
            for (int k = 0; k < s; k++) {
                if (t.equals(g[k][i])) same++;
                else {
                    t = g[k][i];
                    same = 1;
                }
                ans = Math.max(ans, same);
            }
        }
    }

    public static void swap(int y, int x, int ny, int nx) {
        String node = g[y][x];
        g[y][x] = g[ny][nx];
        g[ny][nx] = node;
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(r.readLine());
        s = Integer.parseInt(st.nextToken());
        for (int i = 0; i < s; i++) {
            st = new StringTokenizer(r.readLine());
            String tmp = st.nextToken();
            for (int k = 0; k < s; k++) {
                g[i][k] = "" + tmp.charAt(k);
            }
        }

        f();
        w.write(ans + "\n");
        w.flush();
    }
}
