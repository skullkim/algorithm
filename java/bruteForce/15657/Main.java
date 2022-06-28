//import java.io.BufferedReader;
//import java.io.BufferedWriter;
//import java.io.IOException;
//import java.io.OutputStreamWriter;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.StringTokenizer;

import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static ArrayList<Integer> seq = new ArrayList<>();
    static ArrayList<Integer> ans = new ArrayList<>();
    static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

    static void f(int currIdx) throws IOException {
        if (ans.size() == m) {
            for (Integer nn : ans) {
                w.write(nn + " ");
            }
            w.write("\n");
            return;
        }

        for (int i = currIdx; i < n; i++) {
            ans.add(seq.get(i));
            f(i);
            ans.remove(ans.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(r.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(r.readLine());
        for (int i = 0; i < n; i++) {
            seq.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(seq);
        f(0);
        w.flush();
    }
}
