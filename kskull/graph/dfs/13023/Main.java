import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int people;
    static int friends;
    static ArrayList<ArrayList<Integer>> graph;
    static boolean hasAns = false;

    static void dfs(int currNode, int depth, boolean[] vi) {
        if (depth == 4) {
            hasAns = true;
            return;
        }
        vi[currNode] = true;
        for (int i = 0; i < graph.get(currNode).size(); i++) {
            int nextNode = graph.get(currNode).get(i);
            if (vi[nextNode]) continue;
            dfs(nextNode, depth + 1, vi);
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        people = Integer.parseInt(st.nextToken());
        friends = Integer.parseInt(st.nextToken());
        graph = new ArrayList<>();
        for (int i = 0; i < people; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0, n1, n2; i < friends; i++) {
            st = new StringTokenizer(br.readLine());
            n1 = Integer.parseInt(st.nextToken());
            n2 = Integer.parseInt(st.nextToken());
            graph.get(n1).add(n2);
            graph.get(n2).add(n1);
        }
        
        for (int n = 0; n < people; n++) {
            boolean[] vi = new boolean[people];
            Arrays.fill(vi, false);
            dfs(n, 0, vi);
            if (hasAns) {
                bw.write("1\n");
                bw.flush();
                return;
            }
        }
        bw.write("0\n");
        bw.flush();
        return;
    }
}
