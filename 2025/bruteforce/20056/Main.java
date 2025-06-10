import java.io.*;
import java.util.*;

class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

  static class Pos {
    int y; int x;
    Pos(int y, int x) {
      this.y = y; this.x = x;
    }
  } 
  static Pos[] dir = {new Pos(-1, 0), new Pos(-1, 1), new Pos(0, 1), new Pos(1, 1), new Pos(1, 0),
    new Pos(1, -1), new Pos(0, -1), new Pos(-1, -1)};

  static class Ball {
    int mass; int d; int mv; int tern;
    Ball(int mass, int mv, int d, int tern) {
      this.mass = mass; this.d = d; this.mv = mv; this.tern = tern;
    }

    void incTern() {
      this.tern++;
    }

    @Override
    public String toString() {
      return "{mass: " + mass + ", d: " + d + ", mv: " + mv + ", tern: " + tern + "}";
    }
  }
  static List<Ball>[][] board = new ArrayList[51][51];

  static boolean bf(List<Ball> arr) {
    boolean isOdd = true, isEven = true;
    for (Ball b : arr) {
      if (b.d % 2 == 0) {
        isOdd = false;
      } else {
        isEven = false;
      }
    }

    return isOdd ^ isEven;
  }

  public static void main(String[] args) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine());

    int boardSize, balls, moves;
    boardSize = Integer.parseInt(st.nextToken());
    balls = Integer.parseInt(st.nextToken());
    moves = Integer.parseInt(st.nextToken());

    for (int i = 0; i <= boardSize; i++) {
      for (int k = 0; k <= boardSize; k++) {
        board[i][k] = new ArrayList<Ball>();
      }
    }

    for (int i = 0; i < balls; i++) {
      st = new StringTokenizer(br.readLine());
      int y = Integer.parseInt(st.nextToken());
      int x = Integer.parseInt(st.nextToken());
      Ball b = new Ball(Integer.parseInt(st.nextToken()), 
        Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 0);
      board[y][x].add(b);
    }

    int tern = 0;
    while (moves-- > 0) {
      for (int i = 1; i <= boardSize; i++) {
        for (int k = 1; k <= boardSize; k++) {
          if (board[i][k].isEmpty()) continue;
          List<Ball> remove = new ArrayList<Ball>();
          for (Ball ball : board[i][k]) {
            if (ball.tern != tern) continue;
            remove.add(ball);
            //int y = Math.abs(i + ball.mv * dir[ball.d].y) % boardSize;
            //int x = Math.abs(k + ball.mv * dir[ball.d].x) % boardSize;
            int y = i, x = k;
            for (int mi = 0; mi < ball.mv; mi++) {
              y = y + dir[ball.d].y;
              if (y > boardSize) y = 1;
              else if (y <= 0) y = boardSize;
            }
            for (int mk = 0; mk < ball.mv; mk++) {
              x = x + dir[ball.d].x;
              if (x > boardSize) x =1;
              else if (x <= 0) x = boardSize;
            }
            Pos p = new Pos(y, x);
            ball.incTern();
            //if (p.y != i || p.x != k) {
              board[p.y][p.x].add(ball);
            //}
          }
          board[i][k].removeAll(remove);
        }
      }
      tern++;

      for (int i = 1; i <= boardSize; i++) {
        for (int k = 1; k <= boardSize; k++) {
          List<Ball> arr = board[i][k];
          int bsize = arr.size();
          if (bsize <= 1) continue;
          board[i][k] = new ArrayList<Ball>();
          int mass = 0, d, mv = 0;
          boolean isEvenDir = bf(arr);
          for (Ball b : arr) {
            mass += b.mass; mv += b.mv;
          }
          mass /= 5; mv /= bsize;

          if (mass == 0) continue;
          if (isEvenDir) {
            board[i][k].add(new Ball(mass, mv, 0, tern));
            board[i][k].add(new Ball(mass, mv, 2, tern));
            board[i][k].add(new Ball(mass, mv, 4, tern));
            board[i][k].add(new Ball(mass, mv, 6, tern));
          } else {
            board[i][k].add(new Ball(mass, mv, 1, tern));
            board[i][k].add(new Ball(mass, mv, 3, tern));
            board[i][k].add(new Ball(mass, mv, 5, tern));
            board[i][k].add(new Ball(mass, mv, 7, tern));
          }
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= boardSize; i++) {
      for (int k = 1; k <= boardSize; k++) {
        List<Ball> b = board[i][k];
        if (b.isEmpty()) continue;
        for (Ball bb : b) ans += bb.mass;
      }
    }

    bw.write(ans + "");
    bw.flush();
  }
}
