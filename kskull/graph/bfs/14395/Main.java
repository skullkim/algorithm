import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static Map<Long, Boolean> vi = new HashMap<>();

    static class Calculation {
        private static final int MULTIPLY = 0;
        private static final int PLUS = 1;
        private static final int MINUS = 2;
        private static final int DIVISION = 3;

        public long result;
        public String operation;

        public Calculation(long result, String operation) {
            this.result = result;
            this.operation = operation;
        }

        public Calculation calculate(int op) {
            switch (op) {
                case MULTIPLY:
                    if (vi.getOrDefault(result * result, false) == true) return null;
                    vi.put(result * result, true);
                    return new Calculation(result * result, operation + "*");
                case PLUS:
                    if (vi.getOrDefault(result + result, false) == true) return null;
                    vi.put(result + result, true);
                    return new Calculation(result + result, operation + "+");
                case MINUS:
                    if (vi.getOrDefault(result - result, false) == true) return null;
                    vi.put(result - result, true);
                    return new Calculation(result - result, operation + "-");
                case DIVISION:
                    if (result == 0 || vi.getOrDefault(result / result, false) == true) return null;
                    vi.put(result / result, true);
                    return new Calculation(result / result, operation + "/");
            }
            return null;
        }
    };

    static Queue<Calculation> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        long givenNumber = Integer.parseInt(st.nextToken());
        long target = Integer.parseInt(st.nextToken());
        if (givenNumber == target) {
            bw.write("0" + "\n");
            bw.flush();
            return;
        }

        Calculation answer = null;
        Calculation start = new Calculation(givenNumber, "");
        vi.put(givenNumber, true);
        q.add(start);
        while (!q.isEmpty()) {
            Calculation cal = q.poll();

            if (cal.result > 1e9) continue;
        
            if (cal.result == target) {
                answer = cal;
                break;
            }

            for (int op = 0; op < 4; op++) {
                Calculation nextCalculation = cal.calculate(op);
                if (nextCalculation == null) continue;
                q.add(nextCalculation);
            }
        }

        if (answer == null) {
            bw.write("-1" + "\n");
            bw.flush();
            return;
        }

        bw.write(answer.operation + "\n");
        bw.flush();
    }
}
