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

    static boolean canExpand(Pos pos, int i, char[][] g) {
        boolean a = false;
        if (pos.y == 2 && pos.x == 4) a = true;
        for (int k = 0; k < 4; k++) {
            Pos nextPos = new Pos(pos.y + DIREC.get(k).y * i, pos.x + DIREC.get(k).x * i);
            if (0 > nextPos.y || nextPos.y >= row || 0 > nextPos.x || nextPos.x >= col) {
                 return false;
            }
            if (g[nextPos.y][nextPos.x] != CAN_PUT) {
                return false;
            }
        }
        return true;
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

    static int calculateCrossSize(Pos pos1, Pos pos2) {
        char[][] g = copyGraph();
        g[pos1.y][pos1.x] = PUT;

        int i = 1;
        while (true) {
            if (!canExpand(pos1, i, g)) {
                break;
            }
            for (int k = 0; k < 4; k++) {
                Pos nextPos = new Pos(pos1.y + DIREC.get(k).y * i, pos1.x + DIREC.get(k).x * i);
                g[nextPos.y][nextPos.x] = PUT;
            }
            i++;
        }
//
//        for (int r = 0; r < row; r++) {
//            for (int c = 0; c < col; c++) {
//                System.out.print(g[r][c] + " ");
//            }
//            System.out.println();
//        }
//        System.out.println();

        if (g[pos2.y][pos2.x] != CAN_PUT) {
            return 0;
        }
        g[pos2.y][pos2.x] = PUT;
        int ii = 1;
        while (true) {
            if (!canExpand(pos2, ii, g)) {
                break;
            }
            for (int k = 0; k < 4; k++) {
                Pos nextPos = new Pos(pos2.y + DIREC.get(k).y * ii, pos2.x + DIREC.get(k).x * ii);
                g[nextPos.y][nextPos.x] = PUT;
            }
            ii++;
        }

        int cross1Size = 1 + (i - 1) * 4;
        int cross2Size = 1 + (ii - 1) * 4;

        return cross1Size * cross2Size;
    }

    static void calculateSize(Pos pos1, Pos pos2) {
         answer = Math.max(answer, Math.max(calculateCrossSize(pos1, pos2), calculateCrossSize(pos2, pos1)));
    }

    static void selectTwoPosition(ArrayList<Pos> poses, int idx) {
        if (idx > positiones.size()) return;
        if (poses.size() == 2) {
            Pos pos1 = poses.get(0);
            Pos pos2 = poses.get(1);
            if (graph[pos1.y][pos1.x] != CAN_PUT || graph[pos2.y][pos2.x] != CAN_PUT) return;
            calculateSize(pos1, pos2);
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
