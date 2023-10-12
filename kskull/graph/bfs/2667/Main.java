import java.io.*;
import java.util.*;

public class Main {
    
    static class Pos {
        public int y;
        public int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    };

    static final int LENGTH = 26;
    static final char HOME = '1';
    static final char EMPTY = '0';

    static Pos[] DIREC = new Pos[4];
    static {
        DIREC[0] = new Pos(0, 1);
        DIREC[1] = new Pos(0, -1);
        DIREC[2] = new Pos(1, 0);
        DIREC[3] = new Pos(-1, 0);
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static char[][] graph = new char[LENGTH][LENGTH];
    static boolean[][] vi = new boolean[LENGTH][LENGTH];
    static int length;

    public static int bfs(Pos entryPoint) throws IOException {
        Queue<Pos> q = new LinkedList<>();
        int houses = 0;
        q.add(entryPoint);
        vi[entryPoint.y][entryPoint.x] = true;

        while (!q.isEmpty()) {
            Pos currPos = q.poll();
            if (graph[currPos.y][currPos.x] == HOME) {
                houses++;
            }
            for (int i = 0; i < 4; i++) {
                Pos nextPos = new Pos(currPos.y + DIREC[i].y, currPos.x + DIREC[i].x);
                if (0 > nextPos.y || nextPos.y >= length || 0 > nextPos.x || nextPos.x >= length) {
                    continue;
                }
                if (vi[nextPos.y][nextPos.x] || graph[nextPos.y][nextPos.x] == EMPTY) continue;
                vi[nextPos.y][nextPos.x] = true;
                q.add(nextPos);
            }
        }
        return houses;
    }
    
    public static void main(String[] args) throws IOException {
        for (boolean v[] : vi) {
            Arrays.fill(v, false);
        } 

        st = new StringTokenizer(br.readLine());
        length = Integer.parseInt(st.nextToken());
        for (int i = 0; i < length; i++) {
            String nodes = br.readLine();
            for (int k = 0; k < nodes.length(); k++) {
                graph[i][k] = nodes.charAt(k);
            }
        }

        ArrayList<Integer> houses = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            for (int k = 0; k < length; k++) {
                if (vi[i][k] || graph[i][k] == EMPTY) continue;
                houses.add(bfs(new Pos(i, k)));
            }
        }

        Collections.sort(houses);

        bw.write(houses.size() + "\n");
        for (int i = 0; i < houses.size(); i++) {
            bw.write(houses.get(i) + "\n");
        }

        bw.flush();
    }
}
