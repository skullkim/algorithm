import java.io.*;
import java.util.*;

public class Main {
    static final int WALL = 1;
    static final int EMPTY = 0;
    static final int PIPE = 2;
    static final int MAX_SIZE = 17;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int[][] graph = new int[MAX_SIZE][MAX_SIZE];
    static int houseSize;

    static enum Direction {
        HORIZONTAL,
        VERTICAL,
        DIAGONAL;

        static boolean canMove(Pos pos, Direction direction, int houseSize) {
            Pos nextPos;
            if (direction == Direction.HORIZONTAL) {
                return (new Pos(pos.y, pos.x + 1)).isQualifiedPos(houseSize);
            } else if (direction == Direction.VERTICAL) {
                return (new Pos(pos.y + 1, pos.x)).isQualifiedPos(houseSize);
            } else  {
                return (new Pos(pos.y + 1, pos.x)).isQualifiedPos(houseSize)
                    && (new Pos(pos.y, pos.x + 1)).isQualifiedPos(houseSize)
                    && (new Pos(pos.y + 1, pos.x + 1)).isQualifiedPos(houseSize);
            }
        }
    };

    static class Pos {

        public int y;
        public int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        } 

        public boolean isQualifiedPos(int houseSize) {
            return 0 <= y && y < houseSize
                && 0 <= x && x < houseSize
                && graph[y][x] != WALL;
        }

        @Override
        public String toString() {
            return "y: " + y + ", x: " + x + "\n"; 
        }
    };

    static class Pipe {
        public Pos pos1;
        public Pos pos2;
        public Direction current;

        public Pipe(Pos pos1, Pos pos2, Direction direction) {
            this.pos1 = pos1;
            this.pos2 = pos2;
            this.current = direction;
        }

        public Pipe updatePos(Direction next) {
            Pipe pipe = new Pipe(pos1, pos2, next);
            if (current == Direction.HORIZONTAL && next == Direction.HORIZONTAL) {
                pipe.pos1 = this.pos2;
                pipe.pos2 = new Pos(this.pos2.y, this.pos2.x + 1);
            } else if (current == Direction.HORIZONTAL && next == Direction.DIAGONAL) {
                pipe.pos1 = this.pos2;
                pipe.pos2 = new Pos(this.pos2.y + 1, this.pos2.x + 1);
            } else if (current == Direction.VERTICAL && next == Direction.VERTICAL) {
                pipe.pos1 = this.pos2;
                pipe.pos2 = new Pos(this.pos2.y + 1, this.pos2.x);
            } else if (current == Direction.VERTICAL && next == Direction.DIAGONAL) {
                pipe.pos1 = this.pos2;
                pipe.pos2 = new Pos(this.pos2.y + 1, this.pos2.x + 1);
            } else if (current == Direction.DIAGONAL && next == Direction.HORIZONTAL) {
                pipe.pos1 = this.pos2;
                pipe.pos2 = new Pos(this.pos2.y, this.pos2.x + 1);
            } else if (current == Direction.DIAGONAL && next == Direction.VERTICAL) {
                pipe.pos1 = this.pos2;
                pipe.pos2 = new Pos(this.pos2.y + 1, this.pos2.x);
            } else if (current == Direction.DIAGONAL && next == Direction.DIAGONAL) {
                pipe.pos1 = this.pos2;
                pipe.pos2 = new Pos(this.pos2.y + 1, this.pos2.x + 1);
            }
            return pipe;
        }

        @Override
        public String toString() {
            return "pos1: " + pos1 + ", pos2: " + pos2 + ", direction: " + current.name() + "\n";
        }
    };

    static Queue<Pipe> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        houseSize = Integer.parseInt(st.nextToken());
        for (int i = 0; i < houseSize; i++) {
            st = new StringTokenizer(br.readLine());
            for (int k = 0; k < houseSize; k++) {
                graph[i][k] = Integer.parseInt(st.nextToken());
            }
        }

        if (graph[houseSize - 1][houseSize - 1] == WALL) {
            bw.write("0\n");
            bw.flush();
            return;
        }

        graph[0][0] = PIPE;
        graph[0][1] = PIPE;

        Pipe firstPos = new Pipe(new Pos(0, 0), new Pos(0, 1), Direction.HORIZONTAL);
        q.add(firstPos);
        int answer = 0;
        while (!q.isEmpty()) {
            Pipe pipe = q.poll();
            if (pipe.pos2.y == houseSize -1 && pipe.pos2.x == houseSize - 1) {
                answer++;
                continue;
            }
            if (pipe.current == Direction.HORIZONTAL) {
                if (Direction.canMove(pipe.pos2, Direction.HORIZONTAL, houseSize)) {
                    q.add(pipe.updatePos(Direction.HORIZONTAL));
                }
                if (Direction.canMove(pipe.pos2, Direction.DIAGONAL, houseSize)) {
                    q.add(pipe.updatePos(Direction.DIAGONAL));
                }
            } else if (pipe.current == Direction.VERTICAL) {
                if (Direction.canMove(pipe.pos2, Direction.VERTICAL, houseSize)) {
                    q.add(pipe.updatePos(Direction.VERTICAL));
                }
                if (Direction.canMove(pipe.pos2, Direction.DIAGONAL, houseSize)) {
                    q.add(pipe.updatePos(Direction.DIAGONAL));
                }
            } else if (pipe.current == Direction.DIAGONAL) {
                if (Direction.canMove(pipe.pos2, Direction.HORIZONTAL, houseSize)) {
                    q.add(pipe.updatePos(Direction.HORIZONTAL));
                }
                if (Direction.canMove(pipe.pos2, Direction.VERTICAL, houseSize)) {
                    q.add(pipe.updatePos(Direction.VERTICAL));
                }
                if (Direction.canMove(pipe.pos2, Direction.DIAGONAL, houseSize)) {
                    q.add(pipe.updatePos(Direction.DIAGONAL));
                }
            }
        }

        bw.write(answer + "\n");
        bw.flush();
    }
}
