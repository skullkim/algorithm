import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static boolean[] vi = new boolean[9];
    static ArrayList<Integer> arr = new ArrayList<>();

    static void f(int currN) {
        if (arr.size() == m) {
            for (Integer n : arr) {
                System.out.print(n + " ");
            }
            System.out.println();
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (vi[i]) continue;
            arr.add(i);
            vi[i] = true;
            f(i);
            vi[i] = false;
            arr.remove(arr.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tz = new StringTokenizer(r.readLine());
        n = Integer.parseInt(tz.nextToken());
        m = Integer.parseInt(tz.nextToken());
        f(0);
    }
}
