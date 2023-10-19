import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static final int MAX_SIZE = 16;
    static final char CAN_PUT = '#';
    static final char PUT = '*';

    static int row;
    static int col;
    static int answer = 0;

    static class Pos {
        public int y;
        public int x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public String toString() {
            return "y: " + y + ", x: " + x;  
        }
    };
    static ArrayList<Pos> DIREC = new ArrayList<>();
    static {
        DIREC.add(new Pos(1, 0));
        DIREC.add(new Pos(0, 1));
        DIREC.add(new Pos(-1, 0));
        DIREC.add(new Pos(0, -1));
    }

    static void print(char[][] g) {
        for (int i = 0; i < row; i++) {
            for (int k = 0; k < col; k++) {
                System.out.print(g[i][k] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
    static ArrayList<Pos> positiones = new ArrayList<>();
    static char[][] graph = new char[MAX_SIZE][MAX_SIZE];

    static char[][] copyGraph() {
        char[][] tmp = new char[MAX_SIZE][MAX_SIZE];
        for (int i = 0; i < row; i++) {
            for (int k = 0; k < col; k++) {
                tmp[i][k] = graph[i][k];
            }
        }
        return tmp;
    }

    static boolean canExpand(char[][] g, Pos pos, int crossSize) {
        boolean a = false;
        for (int i = 0; i < 4; i++) {
            Pos nextPos = new Pos(pos.y + DIREC.get(i).y * crossSize, pos.x + DIREC.get(i).x * crossSize);
            if (0 > nextPos.y || nextPos.y >= row || 0 > nextPos.x || nextPos.x >= col) return false;
            if (g[nextPos.y][nextPos.x] != CAN_PUT) return false;
        }
        return true;
    }

    static void calculateCrossSize(Pos pos1, Pos pos2) {
        char[][] g = copyGraph();
        int cross1Size = 0;
        while (true) {
            if (!canExpand(g, pos1, cross1Size)) {
                break;
            }
            for (int i = 0; i < 4; i++) {
                Pos nextPos = new Pos(pos1.y + DIREC.get(i).y * cross1Size, pos1.x + DIREC.get(i).x * cross1Size);
                g[nextPos.y][nextPos.x] = PUT;
            }
            cross1Size++;

            int cross2Size = 0;
            while (true) {
                if (!canExpand(g, pos2, cross2Size)) {
                    break;
                }
                cross2Size++;
                int cross1 = 1 + (cross1Size - 1) * 4;
                int cross2 = 1 + (cross2Size - 1) * 4;
                answer = Math.max(answer, cross1 * cross2);
            }
        }
    }

    static void selectTwoPosition(ArrayList<Pos> poses, int idx) {
        if (idx > positiones.size()) return;
        if (poses.size() == 2) {
            Pos pos1 = poses.get(0);
            Pos pos2 = poses.get(1);
            if (graph[pos1.y][pos1.x] != CAN_PUT || graph[pos2.y][pos2.x] != CAN_PUT) return;
            calculateCrossSize(pos1, pos2);
            return;
        }

        for (int i = idx; i < positiones.size(); i++) {
            poses.add(positiones.get(i));
            selectTwoPosition(poses, i + 1);
            poses.remove(poses.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        row = Integer.parseInt(st.nextToken());
        col = Integer.parseInt(st.nextToken());
        for (int i = 0; i < row; i++) {
            String r = br.readLine();
            for (int k = 0; k < col; k++) {
                graph[i][k] = r.charAt(k);
                positiones.add(new Pos(i, k));
            }
        }


        selectTwoPosition(new ArrayList<>(), 0);
        bw.write(answer + "\n");
        bw.flush();
    }
}
