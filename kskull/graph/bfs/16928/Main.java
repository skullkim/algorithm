import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int[][] graph = new int[11][11];
    static Map<Integer, Integer> ladders = new HashMap<>();
    static Map<Integer, Integer> snakes = new HashMap<>();
    static int snakeNum;
    static int ladderNum;

    static class Step {
        int position;
        int played;

        public Step(int position, int played) {
            this.position = position;
            this.played = played;
        }
    }

    public static void main(String[] args) throws IOException {
        for (int i = 1, number = 1; i <= 10; i++) {
            for (int k = 1; k <= 10; k++) {
                graph[i][k] = number++;
            }
        }

        st = new StringTokenizer(br.readLine());
        ladderNum = Integer.parseInt(st.nextToken());
        snakeNum = Integer.parseInt(st.nextToken());

        for (int i = 0; i < ladderNum; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            ladders.put(from, to);
        }

        for (int i = 0; i < snakeNum; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            snakes.put(from, to);
        }

        Queue<Step> q = new LinkedList<>();
        q.add(new Step(1, 0));
        boolean[] vi = new boolean[101];
        Arrays.fill(vi, false);
        while (!q.isEmpty()) {
            Step step = q.poll();
            vi[step.position] = true;
            if(step.position == 100) {
                bw.write(step.played + "\n");
                bw.flush();
                return;
            }

            for (int i = 1; i <= 6; i++) {
                Step nextStep = new Step(step.position + i, step.played + 1);
                if (nextStep.position > 100 || vi[nextStep.position]) continue;
                if (ladders.get(nextStep.position) != null) {
                    nextStep.position = ladders.get(nextStep.position);
                } else if (snakes.get(nextStep.position) != null) {
                    nextStep.position = snakes.get(nextStep.position);
                }
                q.add(nextStep);
            }
        }
    }
}
