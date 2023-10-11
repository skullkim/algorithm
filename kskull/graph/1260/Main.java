import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int nodes, edges, entryPoint;
    static ArrayList<ArrayList<Integer>> graph;
    static ArrayList<Integer> answer;
    static Queue<Integer> q = new LinkedList<>();
    static boolean[] vi = new boolean[10001];

    static void print() throws IOException{
        for (int i = 0; i < answer.size(); i++) {
            bw.write(answer.get(i) + " ");
        }
        bw.write("\n");
    }

    static void initVi(int nodes) {
        for (int i = 0; i <= nodes; i++) {
            vi[i] = false;
        }
    }

    static void dfs(int currNode) throws IOException {
        vi[currNode] = true;
        answer.add(currNode);

        for (int i = 0; i < graph.get(currNode).size(); i++) {
            int nextNode = graph.get(currNode).get(i);
            if (vi[nextNode]) continue;
            dfs(nextNode);
        }
    }

    static void bfs(int currNode) throws IOException {
        q.add(currNode);
        initVi(nodes);
        vi[currNode] = true;
        answer = new ArrayList<>();

        while (!q.isEmpty()) {
            int node = q.poll();
            answer.add(node);

            for (int i = 0; i < graph.get(node).size(); i++) {
                int nextNode = graph.get(node).get(i);
                if (vi[nextNode]) continue;
                vi[nextNode] = true;
                q.add(nextNode);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        nodes = Integer.parseInt(st.nextToken());
        edges = Integer.parseInt(st.nextToken());
        entryPoint = Integer.parseInt(st.nextToken());

        graph = new ArrayList<>();
        for (int i = 0; i <= nodes; i++) {
            graph.add(new ArrayList<Integer>());
        }

        for (int i = 0, node1, node2; i < edges; i++) {
            st = new StringTokenizer(br.readLine());
            node1 = Integer.parseInt(st.nextToken());
            node2 = Integer.parseInt(st.nextToken());
            graph.get(node1).add(node2);
            graph.get(node2).add(node1);
        }

//        for (int i = 0; i < graph.size(); i++) {
//            for (int k = 0; k < graph.get(i).size(); k++) {
//                bw.write(graph.get(i).get(k) + " ");
//            }
//            bw.write("\n");
//        }

        initVi(nodes);

        answer = new ArrayList<>();
        dfs(entryPoint);
        print();

        bfs(entryPoint);
        print();

        bw.flush();
    }
}
