import java.io.*;
import java.util.*;

public class Main {

    static ArrayList<Integer> arr = new ArrayList<>();
    static int n, m;

    static void f(int currN) {
        if (arr.size() == m) {
            for (Integer nn : arr) {
                System.out.print(nn + " ");
            }
            System.out.println();
        }

        for (int i = currN + 1; i <= n; i++) {
            arr.add(i);
            f(i);
            arr.remove(arr.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(r.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        f(0);
    }
}
