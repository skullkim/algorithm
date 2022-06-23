import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static ArrayList<Integer> arr = new ArrayList<>();

    static void f() {
        if (arr.size() == m) {
            for (Integer nn : arr) {
                System.out.print(nn + " ");
            }
            System.out.println();
            return;
        }

        for (int i = 1; i <= n; i++) {
            arr.add(i);
            f();
            arr.remove(arr.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(r.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        f();
    }
}
