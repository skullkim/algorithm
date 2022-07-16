import java.util.*;
import java.io.*;

public class Main {

    static int leftDays;
    static class Pair {
        public int day;
        public int amount;

        public Pair(int d, int a) {
            day = d;
            amount = a;
        }
    }
    static int[] cache = new int[16];
    static ArrayList<Pair> arr = new ArrayList<>();
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

    static int f(int d) {
        if(d == leftDays + 1) return 0;
        if (d > leftDays + 1) return -987654321;
        if (cache[d] != -1) return cache[d];
        return cache[d] = Math.max(f(d + arr.get(d).day) + arr.get(d).amount, f(d + 1));
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(r.readLine());
        leftDays = Integer.parseInt(st.nextToken());
        for (int i = 0; i <= leftDays; i++) cache[i] = -1;
        arr.add(new Pair(0, 0));
        for (int i = 0; i < leftDays; i++) {
            int day, amount;
            st = new StringTokenizer(r.readLine());
            day = Integer.parseInt(st.nextToken());
            amount = Integer.parseInt(st.nextToken());
            arr.add(new Pair(day, amount));
        }
        w.write(f(1) + "\n");
        w.flush();
    }

}
