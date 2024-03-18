import java.util.*;
import java.io.*;

public class Main {

	static int people, relationships;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static List<List<Integer>> graph;
	static boolean hasAns = false;

	static void dfs(boolean[] vi, int depth, int currNode) {
		if (depth == 4) {
			hasAns = true;
			return;
		}
		vi[currNode] = true;
		for (int i = 0; i < graph.get(currNode).size(); i++) {
			int nextNode= graph.get(currNode).get(i);
			if (vi[nextNode]) continue;
			dfs(vi, depth + 1, nextNode);
		}
	}

	public static void main(String[] args) throws IOException {

		StringTokenizer st = new StringTokenizer(br.readLine());
		people = Integer.parseInt(st.nextToken());
		relationships = Integer.parseInt(st.nextToken());


		graph = new ArrayList<>(people + 1);
		for (int i = 0; i <= people; i++) {
			graph.add(new ArrayList<>());
		}

		for (int i = 0, n1, n2; i < relationships; i++) {
			st = new StringTokenizer(br.readLine());
			n1 = Integer.parseInt(st.nextToken());
			n2 = Integer.parseInt(st.nextToken());
			graph.get(n1).add(n2);
			graph.get(n2).add(n1);
		}

		for (int i = 0; i < people; i++) {
			boolean[] vi = new boolean[people];
			Arrays.fill(vi, false);
			dfs(vi, 0, i);
			if (hasAns) {
				break;
			}
		}

		if (hasAns) {
			bw.write("1\n");
		} else {
			bw.write("0\n");
		}
		bw.flush();
	}
}
